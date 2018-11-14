## 自顶向下，逐步求精--以洗衣机为案例
### 1.什么是自顶向下，逐步求精？
当我们面对一个复杂的问题，我们需要设计一个算法去解决这个问题。我们可以先将这个复杂的大问题分解为相对简单的小问题，找出每个问题的关键，也就是分解逐步求精的过程。自顶向下指的就是这个过程，将大问题分解成小问题，将每个小方法实现好，大问题自然迎刃而解
![自顶向下](https://gss2.bdstatic.com/-fo3dSag_xI4khGkpoWK1HF6hhy/baike/w%3D268%3Bg%3D0/sign=64329eeebc7eca8012053ee1a918f0e0/ac4bd11373f082028c8ca9f247fbfbedaa641be4.jpg)
### 2.洗衣机中的自顶向下分解
我们要洗衣服，可以将整个大过程分解成几个小的过程，例如漂洗、浸泡、脱水。而这三个过程里每个又可以分为注水、洗衣机电动机运作、排水等。所以我们只需要设计好小的过程，而相对大的过程又由这些的小的过程组成。
### 3.洗衣机案例的过程
1. 选择洗衣模式、注水高度  
2. 注水到一定高度
3. 电机转动左三次右三次
4. 排水过滤，注水到一定高度，浸泡
5. 排水后脱水（电机转动）
6. 结束
### 4.洗衣机案例的伪代码
water_in_switch(open_close)  // open 打开上水开关，close关闭  
water_out_switch(open_close)  // open 打开排水开关，close关闭  
get_water_volume()  //返回洗衣机内部水的高度  
```
 Read 使用者选择的洗衣模式
    Read 使用者选择的注水高度depth
    for counter 1 to 2 by 1
        water_in_switch(open) 
        if get_water_volume() == depth 
        then water_in_switch(close) 
        for counter 1 to 3 by 1
            motor_run(left)
        end
        for counter 1 to 3 by 1
            motor_run(right)
        end
        water_out_switch(open) 
        water_out_switch(close) 
    end
    halt(success)
    for counter 1 to 3 by 1
            motor_run(left)
    end
    for counter 1 to 3 by 1
        motor_run(right)
    end
```

