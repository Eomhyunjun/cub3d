# cub3D

42Seoul Circle 2 과제. minilibx 그래픽 라이브러리를 사용하여 Wolfenstein 3D 스타일의 레이캐스팅 렌더러 구현.

## 과제 설명

`.cub` 맵 파일을 파싱하고, 레이캐스팅(Raycasting) 알고리즘으로 1인칭 시점의 3D 화면을 렌더링한다. 벽 텍스처, 스프라이트, 키보드 이동/회전을 지원한다.

## 주요 구현 내용

### 맵 파싱
- `.cub` 파일에서 해상도, 벽 텍스처 경로(N/S/W/E), 바닥/천장 RGB, 맵 데이터 파싱
- 맵 유효성 검증 (벽으로 둘러싸여 있는지, 플레이어 위치 등)

### 레이캐스팅
- DDA(Digital Differential Analysis) 알고리즘으로 벽까지의 거리 계산
- 벽 높이에 따른 원근 투영
- 벽면 방향(N/S/W/E)에 따라 다른 텍스처 매핑

### 스프라이트
- 맵 내 스프라이트 오브젝트 렌더링
- 거리 기반 정렬 및 Z-buffer를 이용한 벽 뒤 가림 처리

### 입력 처리
- W/A/S/D 이동, 좌/우 화살표 회전
- ESC/Q 종료

### BMP 저장
- `--save` 옵션으로 첫 프레임을 bitmap 파일로 저장

## 프로젝트 구조

```
cub3d/
├── main.c
├── cub3.h
├── map.cub                    # 샘플 맵
├── srcs/
│   ├── parsing_all.c          # 파싱 진입점
│   ├── parse_info/            # 맵 정보 파싱 (해상도, 텍스처, 색상)
│   ├── map_parsing/           # 맵 데이터 파싱 및 검증
│   ├── graphic/               # 레이캐스팅, 텍스처, 키 입력, 스프라이트
│   └── save/                  # BMP 저장
├── utils/
│   ├── libft/                 # libft 라이브러리
│   └── gnl/                   # get_next_line
└── mlx/                       # minilibx 라이브러리
```

## 사용 기술

- C
- minilibx (42 그래픽 라이브러리)
- Raycasting (DDA 알고리즘)
- Makefile

## 학습 내용

- 레이캐스팅 알고리즘과 원리
- 텍스처 매핑
- 스프라이트 렌더링 및 Z-buffer
- 2D 맵 데이터를 3D로 투영하는 과정
- 이벤트 기반 입력 처리

## 빌드

```bash
make        # cub3D 빌드
make clean  # 오브젝트 파일 삭제
make fclean # 전체 삭제
make re     # 재빌드
```

## 실행

```bash
./cub3D map.cub           # 게임 실행
./cub3D map.cub --save    # 첫 프레임 BMP 저장
```
