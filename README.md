This project aims to implement an AMR service robot to deliver food at a pizza restaurant.
=============================================================================================

## 패키지 빌드
--------------------------------------------------------------------

```console
cd ~/b3_ws
rm -rf ./install ./build ./log
colcon build 

source install/setup.bash
```
## 실행하는 순서
--------------------------------------------------------------------

### 1.

```console
ros2 run pizza_serving_bot kitchen 
```

### 2. 

```console
ros2 run pizza_serving_bot table 
```

### 3. 

```console
ros2 run pizza_serving_bot amr 
```

### 4. 

```console

```

### 5. 

```console
ros2 run pizza_serving_bot display 
