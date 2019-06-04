cmake_minimum_required(VERSION 3.12)
project(doom_nukem C)

#set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm -framework OpenGL -framework AppKit -framework OpenCl")
#
#include_directories(includes)
#include_directories(libft/includes)
#
#aux_source_directory(libft LIBFT_SRC)
#add_library(ft STATIC ${LIBFT_SRC})
#
#add_executable(doom_nukem           src/collision.c
#                                    src/debug.c
#                                    src/draw.c
#                                    src/drawsector.c
#                                    src/init.c
#                                    src/key.c
#                                    src/main.c
#                                    src/mapping.c
#                                    src/mouse.c
#                                    src/parse_utils.c
#                                    src/parse_validation.c
#                                    src/player_transform.c
#                                    src/print.c
#                                    src/ray.c
#                                    src/resourse.c
#                                    src/sdlmain.c
#                                    src/sky.c
#                                    src/utils.c
#                                    includes/errors.h)
#
#target_link_libraries(doom_nukem ft)
#target_link_libraries(doom_nukem ${CMAKE_SOURCE_DIR} -L/Users/ablizniu/.brew/Cellar/sdl2/2.0.9_1/lib -lSDL2 -lm)

set(CMAKE_C_STANDARD 99)
set(set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/Cmake"))

find_library(SDL SDL)
#find_library(SDL_ttf SDL2_ttf)


include_directories(includes)
include_directories(libft/includes)
include_directories(/Library/Frameworks/SDL2.framework/Headers)
include_directories(frameworks/SDL2_ttf.framework/Headers)

AUX_SOURCE_DIRECTORY(libft LIBFT_SRC)
add_library(ft ${LIBFT_SRC})

set(SOURCE_FILES
        src/collision.c
        src/debug.c
        src/draw.c
        src/drawsector.c
        src/init.c
        src/key.c
        src/main.c
        src/mapping.c
        src/mouse.c
        src/parse_utils.c
        src/parse_validation.c
        src/player_transform.c
        src/print.c
        src/ray.c
        src/resourse.c
        src/sdlmain.c
        src/sky.c
        src/utils.c
        includes/errors.h)

add_executable(doom_nukem ${SOURCE_FILES})
target_link_libraries(doom_nukem ft ${SDL} )