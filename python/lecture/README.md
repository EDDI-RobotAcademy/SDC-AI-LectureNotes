# Anaconda Download  
https://www.anaconda.com/download  

위 링크에서 다운로드 진행
(편의상 Jupyter Notebook 이라는 것에서 내용을 확인 할 수 있도록 구성)  

# How to Install
```make
mv ~/Downloads/Anaconda3-2024.02-1-Linux-x86_64.sh ./
chmod +x Anaconda3-2024.02-1-Linux-x86_64.sh
./Anaconda3-2024.02-1-Linux-x86_64.sh
```

위 명령들을 입력하여 설치합니다.  
중간에 License 동의하냐는 메시지가 나오는데  
잘 보고 Enter 혹은 yes를 입력해야함  

# Path Connection
```make
vi ~/.bashrc
```

이후 맨 아래로 이동해서 아래 내용을 추가함  
```make
export PATH="$PATH:/home/eddi/anaconda3/bin"
```

다음으로 변경 내역을 적용해야함
```make
source ~/.bashrc
```

# How to check installation
```make
conda list
```

# How to execute jupyter notebook
```make
jupyter notebook
```
