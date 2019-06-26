cmake_minimum_required(VERSION 3.14)
project(doom C)

set(CMAKE_C_STANDARD 11)
execute_process(COMMAND whoami OUTPUT_VARIABLE current_user OUTPUT_STRIP_TRAILING_WHITESPACE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

include_directories(libft/includes)
include_directories(engine/includes)

include_directories(/Users/${current_user}/.brew/Cellar/sdl2_image/2.0.4/include/SDL2)
include_directories(/Users/${current_user}/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2)
include_directories(/Users/${current_user}/.brew/Cellar/sdl2/2.0.9_1/include/SDL2)
include_directories(/Users/${current_user}/.brew/Cellar/sdl2_mixer/2.0.4/include/SDL2)

aux_source_directory(libft LFT_SRC)
add_library(ft STATIC ${LFT_SRC})


add_executable(doom
        engine/src/collision.c
        engine/src/collision_2.c
        engine/src/cr_cols_init.c
        engine/src/draw.c
        engine/src/draw_1.c
        engine/src/draw_2.c
        engine/src/drawsector.c
        engine/src/drawsector_1.c
        engine/src/init.c
        engine/src/key.c
        engine/src/key_2.c
        engine/src/ligth.c
        engine/src/lst_utils.c
        engine/src/main.c
        engine/src/mapping.c
        engine/src/mapping_2.c
        engine/src/mouse.c
        engine/src/parse_utils.c
        engine/src/parse_utils_2.c
        engine/src/parse_utils_3.c
        engine/src/parse_utils_4.c
        engine/src/parse_utils_5.c
        engine/src/parse_validation.c
        engine/src/parse_validation_2.c
        engine/src/parse_validation_3.c
        engine/src/parse_validation_4.c
        engine/src/player_transform.c
        engine/src/player_transform_2.c
        engine/src/print.c
        engine/src/ray.c
        engine/src/ray_2.c
        engine/src/resourse.c
        engine/src/sdlmain.c
        engine/src/shooting.c
        engine/src/sky.c
        engine/src/sprite.c
        engine/src/start_menu.c
        engine/src/utils.c
        )


target_link_libraries(doom ${CMAKE_SOURCE_DIR} -L/Users/${current_user}/.brew/Cellar/sdl2/2.0.9_1/lib -lSDL2 -L/Users/${current_user}/.brew/Cellar/sdl2_image/2.0.4/lib -lSDL2_image -L/Users/${current_user}/.brew/Cellar/sdl2_ttf/2.0.15/lib -lSDL2_ttf -L/Users/${current_user}/.brew/Cellar/sdl2_mixer/2.0.4/lib -lSDL2_mixer ft)
