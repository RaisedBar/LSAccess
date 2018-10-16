using System;
using System.Xml;
using Microsoft.Win32;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Xml.Linq;
using WixSharp;
using WixSharp.CommonTasks;


class Script
{
    static public void Main(string[] args)
    {
        try
        {
            var LSAccessSetup = new Project("LSAccess",
new Dir(new Id("ExeFolder"), @"%ProgramFilesFolder%\Raised Bar\LSAccess",
new WixSharp.File(@"..\Files\Program Files\LSAccess.exe",
new WixSharp.FileShortcut("LSAccess", @"%Desktop%")),
            new ExeFileShortcut("Uninstall LSAccess", "[SystemFolder]msiexec.exe", "/x [ProductCode]"),

            // Configuration files
            new Dir(new Id("DataFiles"), @"%CommonAppDataFolder%\Raised Bar\LSAccess",
            new DirPermission("Everyone", GenericPermission.All),
                        new WixSharp.Files(@"..\Files\ProgramData\*.*")),

                        // Start menu and shortcuts
                        new Dir(@"%ProgramMenu%\Raised Bar\LSAccess",
                                                                                                new ExeFileShortcut("LSAccess", "[ExeFolder]LSAccess.exe", ""),
                                                                                                new ExeFileShortcut("Uninstall LSAccess", "[SystemFolder]msiexec.exe", "/x [ProductCode]"))));

                                    if (args.Length != 0)
            {
                switch (args[0])
                {
                    case "ProgressOnly": LSAccessSetup.UI = WUI.WixUI_ProgressOnly; break;
                    case "Minimal": LSAccessSetup.UI = WUI.WixUI_Minimal; break;
                    case "InstallDir": LSAccessSetup.UI = WUI.WixUI_InstallDir; break;
                    case "FeatureTree": LSAccessSetup.UI = WUI.WixUI_FeatureTree; break;
                    case "Mondo": LSAccessSetup.UI = WUI.WixUI_Mondo; break;
                }
            }

            LSAccessSetup.Platform = Platform.x86;
            LSAccessSetup.LicenceFile = @"..\files\programdata\license.rtf";
            LSAccessSetup.GUID = new Guid("2AEE6F7A-8AAE-4E91-9525-A2905E30DEB6");
            LSAccessSetup.InstallPrivileges = InstallPrivileges.elevated;
            LSAccessSetup.OutFileName = "LSAccess";

            Compiler.BuildMsi(LSAccessSetup);
        }
        catch (System.Exception ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}