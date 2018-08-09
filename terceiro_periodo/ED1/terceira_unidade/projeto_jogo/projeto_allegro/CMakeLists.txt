cmake_minimum_required(VERSION 3.12)
project(projeto_allegro)

set(CMAKE_C_STANDARD 11)

include_directories(src/funcoes)

INCLUDE_DIRECTORIES( allegro5/include )

LINK_DIRECTORIES( /usr/lib/ )

add_executable(projeto_allegro
        imagens/imgsJonSnow/imgs/ABOUT.png
        imagens/imgsJonSnow/imgs/EXIT.png
        imagens/imgsJonSnow/imgs/HOW_TO_PLAY.png
        imagens/imgsJonSnow/imgs/JON_SNOW.jpeg
        imagens/imgsJonSnow/imgs/LOAD_GAME.png
        imagens/imgsJonSnow/imgs/NEW_GAME.png
        imagens/imgsJonSnow/BaRjs.sh
        imagens/imgsJonSnow/jon_snow_teste.c
        src/funcoes/funcoes_basicas_init.c
        src/funcoes/funcoes_basicas_init.h
        BaR.sh)



add_library(lallegro SHARED /usr/lib/liballegro.so)

set_target_properties(lallegro PROPERTIES LINKER_LANGUAGE C)

TARGET_LINK_LIBRARIES(projeto_allegro
        allegro_acodec
        allegro_audio
        allegro_color
        allegro_dialog
        allegro_image
        allegro_main
        allegro_memfile
        allegro_physfs
        allegro_primitives
        allegro_ttf
        allegro_font
        allegro)
