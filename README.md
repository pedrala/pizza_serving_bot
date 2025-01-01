## Description
This project aims to implement an AMR service robot to deliver food at a pizza restaurant.

## Capture
<p align="center">
  <img src="capture/kiosk_order.png" alt="kiosk_order" width="500">
  <img src="capture/order_confirm.png" alt="order_confirm" width="200">
</p>

<p align="center">
  <img src="capture/kitchen_display.png" alt="kitchen_display.png" width="1000">
</p>

<p align="center">
  <img src="capture/servicebot_status.png" alt="servicebot_status" width="300">
  <img src="capture/servicebot_status_ready.png" alt="servicebot_status_ready" width="300">
</p>


## 패키지 빌드

```console
cd ~/b3_ws
rm -rf ./install ./build ./log
colcon build 

source install/setup.bash
```
## 실행하는 순서


### 0. API서버 실행(DB 저장 및 조회)

```console
python3 api_server.py

```

### 1. 주문정보 DB 에 저장(API서버 운영), ROS2 서비스 요청 결과값 키오스크에 전송. [취소]시 취소서비스(CancelService) 실행, [완료]시 테이블 목표 위치를 AMR봇에 서비스(GoalLoc)로 보냄

```console
ros2 run pizza_serving_bot kitchen 
```

### 2. 테이블에서 ROS2 주문정보 서비스(OrderService) 요청 보냄, 직원호출 토픽(CallManager) 발행

```console
ros2 run pizza_serving_bot kiosk 
```

### 3. AMR봇 디스플레이에 구독받은 주문정보, 상태값 표시, 목표테이블로 네비게이션, 도착후 확인 누르면 원위치 복귀 

```console
ros2 run pizza_serving_bot amr 

```