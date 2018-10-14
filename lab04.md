# 色彩与编码
----------
如今我们活在一个色彩缤纷的世界上，我们能用肉眼去感知这个世界的颜色，是因为肉眼受到电磁波辐射能刺激后所引起的视觉神经感觉。但有时候我会想，电脑不是人脑，又是怎么能展现出我们所需要看到的颜色的呢？  
![world](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1539505575979&di=5c27c7ab8a04324109f46ea073305017&imgtype=0&src=http%3A%2F%2Fimgsrc.baidu.com%2Fimgad%2Fpic%2Fitem%2F242dd42a2834349b847f99acc2ea15ce36d3be9a.jpg)

查阅了相关资料，是科学家们发现，我们的视网膜上有三种颜色感光细胞，而就是这三种细胞便能让我们对不同频率的颜色做出反应。而这三种颜色就是我们常说的三原色：红色、蓝色、绿色。  
![三原色](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1539505801614&di=e713491792da0e699c731e05a967dc76&imgtype=0&src=http%3A%2F%2Fh.hiphotos.baidu.com%2Fzhidao%2Fpic%2Fitem%2Fc8ea15ce36d3d539c19ce7aa3c87e950352ab032.jpg)

这种由三原色叠加得到我们想要颜色的模式叫做“RGB模式”。那要怎么表示这三种颜色的叠加程度呢？计算机有多种颜色编码模式，最常见的便是真彩色（TrueColor）。用24位二进制数来表示，每8位（0~255）表示一种原色的叠加程度。所以我们常见计算机表示一种颜色，例如黄色，可以用（255，255，0)或者#FFFF00来表示。指的就是全红 + 全绿 = 黄色。
![黄色](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1539506150088&di=a22e7691c58b44387c3b1cc11c6d1c3d&imgtype=0&src=http%3A%2F%2Fpic32.photophoto.cn%2F20140922%2F0017031000546394_b.jpg)

除了真彩色，当然还有其他的编码模式，例如HiColor。它是用16位二进制数来表示颜色，其中每5位表示一种原色的叠加程度，还有1位表示颜色的透明度。这种表示方法，从位数便可得知它所能表示的颜色比真彩色少。

除此之外，我们在现实生活中还会听到一种叫“CMYK模式"，即印刷四色模式。它是彩色印刷时采用的一种套色模式，利用色料的三原色混色原理，加上黑色油墨，共计四种颜色混合叠加，形成所谓“全彩印刷”。四种标准颜色是：C：Cyan = 青色，又称为‘天蓝色’或是‘湛蓝’M：Magenta = 品红色，又称为‘洋红色’；Y：Yellow = 黄色；K：key=关键，这里的K指代key，是打印设备校准用的。另外，K:还可以代表Black，黑色，因为印刷用黑色用的比较多。这里就不多作介绍了。

想知道某张图片的颜色RGB值？用画图软件取色器取下色就可以知道了。
![颜色](https://gss0.bdstatic.com/94o3dSag_xI4khGkpoWK1HF6hhy/baike/c0=baike150,5,5,150,50/sign=7bcbda10f8198618554ae7d62b844516/a1ec08fa513d2697913e572c55fbb2fb4216d8d6.jpg)


