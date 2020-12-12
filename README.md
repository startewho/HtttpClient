# HtttpClient
 A HttpClient with libCurl
# Install
下载解压缩vckpg,在其路径运行
vcpkg install curl
vcpkg integrate install
然后打开项目即可编译使用curl来做传递
# Notice
目前:对于Https的研究,还需要更多的时间.内置了OpenSSL,但是需要研究.

libucrl.x64.nupkg

PS C:\Users\hoolo> vcpkg export curl --nuget --triplet=x64-windows
The following packages are already built and will be exported:
    curl:x64-windows
  * zlib:x64-windows
Additional packages (*) need to be exported to complete this operation.
Exporting package zlib:x64-windows...
Exporting package curl:x64-windows...
Packing nuget package...
NuGet package exported at: D:\Tool\vcpkg\vcpkg-export-20201212-225509.1.0.0.nupkg

With a project open, go to Tools->NuGet Package Manager->Package Manager Console and paste:
    Install-Package vcpkg-export-20201212-225509 -Source "D:\Tool\vcpkg"