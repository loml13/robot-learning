# reference 参考资料

教材配套代码、第三方开源项目等参考资料。**非个人原创内容**,版权归原作者。

## 内容

| 目录 | 说明 | 形式 |
|---|---|---|
| [slambook2/](slambook2/) | 《视觉SLAM十四讲》(高翔)官方配套代码,原仓库 <https://github.com/gaoxiang12/slambook2> | 文件拷贝 |
| [FAST_LIO/](FAST_LIO/) | 紧耦合激光-惯性里程计,原仓库 <https://github.com/hku-mars/FAST_LIO> | git 子模块 |

## 子模块说明

`FAST_LIO/` 是 git 子模块。首次克隆本仓库后需初始化:

```bash
git submodule update --init reference/FAST_LIO
```

拉取上游更新:`git submodule update --remote reference/FAST_LIO`

> 注:`slambook2.pdf`(教材电子版)因版权与体积原因不纳入版本管理,仅保留在本地。
