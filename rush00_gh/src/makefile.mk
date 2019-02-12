RETRO_OBJ += src/main.o \
             src/game.o \
             src/collide.o \
             src/control.o \
             src/enemy.o \
             src/move.o \
             src/player.o \
             src/render.o \
             src/spawn.o \
             src/laser.o \
             src/environnement.o

$(eval $(call target_bin,ft_retro,RETRO_OBJ,RETRO_BIN))
$(RETRO_BIN): INCLUDE += include src
$(RETRO_BIN): LDLIBS  += ncurses