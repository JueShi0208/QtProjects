官方：
    SVGA介绍参考http://svga.io/
    SVGA格式参考https://github.com/svga/SVGA-Format

说明：
    这是一个播放svga动画的项目，svgaplayer编译依赖于protobuf、zlib。
    对于有的版本Qt版本编译不通过的问题，可能是由于C++11，对protobuf或者zlib支持有问题，
    解决方案就是升级protobuf或者zlib。请去官方网站下载protobuf和zlib
    目前官网放出了svga的iOS、Android、Web版本，没有PC版的，因此我这个就是就PC版本。
    此代码来源于https://github.com/moon-l/SvgaPlayer，但是删除了其他多余的部分，只保留了Qt本身的播放svga。