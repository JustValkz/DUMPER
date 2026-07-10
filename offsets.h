#pragma once
/* =============================================================
/*                       Valkz offsets                         
/* ------------------------------------------------------------- 
/*  Dumped With     : ValkzDumper.exe                               
/*  Roblox Version  : version-36a2600cebf1487d
/*  Dumper Version  : 1.0
/*  Dumped At       : 03:09:00 PM
/*  Total Offsets   : 117
/* ------------------------------------------------------------- 
/*  Discord:                                          
/*  luv.yvsf (follow me on insta too)                    
/* =============================================================
*/

#include <cstdint>
#include <string>

// clang-format off
namespace offsets {
    inline constexpr const char* roblox_version = "version-36a2600cebf1487d";

    namespace AirProperties {
        inline constexpr uintptr_t AirDensity = 0x18;
    }

    namespace Atmosphere {
        inline constexpr uintptr_t Density = 0x0;
        inline constexpr uintptr_t Glare = 0x0;
        inline constexpr uintptr_t Haze = 0x0;
        inline constexpr uintptr_t Offset = 0x0;
    }

    namespace Attachment {
        inline constexpr uintptr_t Position = 0x80;
    }

    namespace BasePart {
        inline constexpr uintptr_t Primitive = 0x128;
    }

    namespace ByteCode {
        inline constexpr uintptr_t Pointer = 0x10;
        inline constexpr uintptr_t Size = 0x4;
    }

    namespace Camera {
        inline constexpr uintptr_t CFrame = 0xC0;
        inline constexpr uintptr_t CameraSubject = 0xC8;
        inline constexpr uintptr_t CameraType = 0x138;
        inline constexpr uintptr_t FieldOfView = 0x140;
        inline constexpr uintptr_t ImagePlaneDepth = 0x2D0;
        inline constexpr uintptr_t Position = 0xE4;
        inline constexpr uintptr_t Rotation = 0xC0;
        inline constexpr uintptr_t Viewport = 0x28C;
        inline constexpr uintptr_t ViewportInt16 = 0x28C;
        inline constexpr uintptr_t ViewportSize = 0x2C8;
    }

    namespace DataModel {
        inline constexpr uintptr_t GameLoaded = 0x668;
        inline constexpr uintptr_t JobId = 0x120;
        inline constexpr uintptr_t RunService = 0x3C0;
        inline constexpr uintptr_t ServerIP = 0x650;
        inline constexpr uintptr_t Workspace = 0x160;
    }

    namespace FakeDataModel {
        inline constexpr uintptr_t Pointer = 0x84ABC88;
        inline constexpr uintptr_t RealDataModel = 0x1D0;
    }

    namespace Humanoid {
        inline constexpr uintptr_t HumanoidStateID = 0x20;
    }

    namespace InputObject {
        inline constexpr uintptr_t MousePosition = 0xD4;
    }

    namespace Instance {
        inline constexpr uintptr_t AttributeList = 0x18;
        inline constexpr uintptr_t AttributeToNext = 0x58;
        inline constexpr uintptr_t ChildrenEnd = 0x8;
        inline constexpr uintptr_t ChildrenStart = 0x70;
        inline constexpr uintptr_t ClassDescriptor = 0x18;
        inline constexpr uintptr_t ClassName = 0x8;
        inline constexpr uintptr_t Name = 0x98;
        inline constexpr uintptr_t Parent = 0x68;
    }

    namespace Lighting {
        inline constexpr uintptr_t Ambient = 0xF8;
        inline constexpr uintptr_t Atmosphere = 0x1D8;
        inline constexpr uintptr_t Brightness = 0x110;
        inline constexpr uintptr_t EnvironmentDiffuseScale = 0x140;
        inline constexpr uintptr_t EnvironmentSpecularScale = 0x140;
        inline constexpr uintptr_t ExposureCompensation = 0x0;
        inline constexpr uintptr_t FogEnd = 0x124;
        inline constexpr uintptr_t FogStart = 0x0;
        inline constexpr uintptr_t GlobalShadows = 0x12C;
        inline constexpr uintptr_t OutdoorAmbient = 0xF8;
        inline constexpr uintptr_t ShadowSoftness = 0x130;
        inline constexpr uintptr_t Sky = 0x1C8;
    }

    namespace LocalScript {
        inline constexpr uintptr_t Bytecode = 0x0;
        inline constexpr uintptr_t Hash = 0x8;
    }

    namespace Model {
        inline constexpr uintptr_t PrimaryPart = 0x258;
        inline constexpr uintptr_t Scale = 0x100;
    }

    namespace ModuleScript {
        inline constexpr uintptr_t Bytecode = 0x0;
        inline constexpr uintptr_t Hash = 0x8;
    }

    namespace MouseService {
        inline constexpr uintptr_t InputObject = 0x100;
        inline constexpr uintptr_t InputObject2 = 0xF0;
        inline constexpr uintptr_t MousePosition = 0xD4;
    }

    namespace Player {
        inline constexpr uintptr_t AccountAge = 0x35C;
        inline constexpr uintptr_t CameraMode = 0x358;
        inline constexpr uintptr_t Character = 0x298;
        inline constexpr uintptr_t DisplayName = 0xB0;
        inline constexpr uintptr_t HealthDisplayDistance = 0x390;
        inline constexpr uintptr_t LocalPlayer = 0x130;
        inline constexpr uintptr_t LocaleId = 0x738;
        inline constexpr uintptr_t MaxZoomDistance = 0x368;
        inline constexpr uintptr_t MinZoomDistance = 0x36C;
        inline constexpr uintptr_t ModelInstance = 0x298;
        inline constexpr uintptr_t Mouse = 0x11D8;
        inline constexpr uintptr_t NameDisplayDistance = 0x3A0;
        inline constexpr uintptr_t UserId = 0x88;
    }

    namespace Players {
        inline constexpr uintptr_t LocalPlayer = 0x130;
    }

    namespace Primitive {
        inline constexpr uintptr_t Flags = 0x1;
        inline constexpr uintptr_t PrimitiveFlags = 0x1;
    }

    namespace PrimitiveFlags {
        inline constexpr uintptr_t Anchored = 0x2;
        inline constexpr uintptr_t CanCollide = 0x8;
        inline constexpr uintptr_t CanQuery = 0x20;
        inline constexpr uintptr_t CanTouch = 0x10;
    }

    namespace RenderView {
        inline constexpr uintptr_t LightingValid = 0x228;
        inline constexpr uintptr_t SkyboxValid = 0x28D;
    }

    namespace Sky {
        inline constexpr uintptr_t MoonTextureId = 0x218;
        inline constexpr uintptr_t SkyboxBk = 0xC8;
        inline constexpr uintptr_t SkyboxDn = 0xF8;
        inline constexpr uintptr_t SkyboxFt = 0x128;
        inline constexpr uintptr_t SkyboxLf = 0x158;
        inline constexpr uintptr_t SkyboxRt = 0x188;
        inline constexpr uintptr_t SkyboxUp = 0x1B8;
        inline constexpr uintptr_t SunTextureId = 0x1E8;
    }

    namespace Sound {
        inline constexpr uintptr_t SoundId = 0xC8;
        inline constexpr uintptr_t Volume = 0x11C;
    }

    namespace TaskScheduler {
        inline constexpr uintptr_t JobEnd = 0xD0;
        inline constexpr uintptr_t JobName = 0x18;
        inline constexpr uintptr_t JobStart = 0xC8;
        inline constexpr uintptr_t MaxFPS = 0xB0;
        inline constexpr uintptr_t MaxFps = 0xB0;
        inline constexpr uintptr_t Pointer = 0x8041EC8;
    }

    namespace Terrain {
        inline constexpr uintptr_t GrassLength = 0x188;
        inline constexpr uintptr_t WaterReflectance = 0x190;
        inline constexpr uintptr_t WaterTransparency = 0x194;
        inline constexpr uintptr_t WaterWaveSize = 0x198;
        inline constexpr uintptr_t WaterWaveSpeed = 0x19C;
    }

    namespace Value {
        inline constexpr uintptr_t Value = 0x1B8;
    }

    namespace VisualEngine {
        inline constexpr uintptr_t Dimensions = 0xAB0;
        inline constexpr uintptr_t FakeDataModel = 0xA90;
        inline constexpr uintptr_t Pointer = 0x81D61C8;
        inline constexpr uintptr_t RenderView = 0xBB8;
        inline constexpr uintptr_t ViewMatrix = 0x150;
    }

    namespace Workspace {
        inline constexpr uintptr_t CurrentCamera = 0x488;
        inline constexpr uintptr_t DistributedGameTime = 0x488;
        inline constexpr uintptr_t Raycast = 0x794960;
        inline constexpr uintptr_t ReadOnlyGravity = 0x998;
        inline constexpr uintptr_t World = 0x3E0;
    }

    namespace World {
        inline constexpr uintptr_t AirProperties = 0x218;
        inline constexpr uintptr_t FallenPartsDestroyHeight = 0x208;
        inline constexpr uintptr_t Gravity = 0x210;
        inline constexpr uintptr_t Primitives = 0x288;
        inline constexpr uintptr_t WorldSteps = 0x680;
        inline constexpr uintptr_t worldStepsPerSec = 0x680;
    }

} // namespace offsets
