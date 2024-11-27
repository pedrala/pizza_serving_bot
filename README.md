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

### 1. 주문정보 DB 에 저장, ROS2 서비스 요청 결과값 키오스크에 전송. [취소]시 취소 서비스 실행, [완료]시 네비게이션 목표 테이블 토픽 발행, AMR봇 디스플레이에 표시할 주문정보 토픽 발행

```console
ros2 run pizza_serving_bot kitchen 
```

### 2. 테이블에서 ROS2 주문정보 서비스 요청 보냄, 직원호출 토픽 발행

```console
ros2 run pizza_serving_bot kiosk 
```

### 3. AMR봇 위치정보 발행, in

```console
ros2 run pizza_serving_bot amr 
```

### 4. AMR봇 디스플레이에 구독받은 주문정보, 상태값 표시

```console
ros2 run pizza_serving_bot display 

```

### 5. AMR봇 테이블 목표 위치로 네이게이션

```console

