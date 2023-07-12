Please scroll down for the English version of the readme.

---

配置systemc可以参考我的[博文](https://zhuanlan.zhihu.com/p/638360098)（也参考了很多别人的经验，但这篇比较适合本工程）。

主程序目前在 sc-code/sm 中，在sm文件夹下运行【make GPGPU_test】编译程序，运行【./BASE --inssrc imem --metafile vecadd/vecadd.riscv.meta --datafile vecadd/vecadd.riscv.data】来获取输出结果。

---

To configure systemc, you can refer to my [blog post](https://zhuanlan.zhihu.com/p/638360098) (I also refer to the experience of many others, but this article is more suitable for this project).

The main program is currently in sc-code/sm, run [make GPGPU_test] to compile the program under the sm folder, and run [./BASE --inssrc imem --metafile vecadd/vecadd.riscv.meta --datafile vecadd/vecadd. riscv.data] to get the output.
