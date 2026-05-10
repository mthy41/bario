SRC_DIR = ./src
OUTPUT_DIR = ./target
BIN_DIR = $(OUTPUT_DIR)/bin
BIN_NAME = $(BIN_DIR)/bario

src = $(addprefix $(SRC_DIR)/, $(1))

UTILS_OBJ = $(OUTPUT_DIR)/utils.o
PARTICLE_OBJ = $(OUTPUT_DIR)/particle.o
PLAYER_OBJ = $(OUTPUT_DIR)/player.o
FOOD_OBJ = $(OUTPUT_DIR)/food.o
MAIN_OBJ = $(OUTPUT_DIR)/main.o

$(shell mkdir -p $(OUTPUT_DIR))

$(BIN_NAME): $(UTILS_OBJ) $(PARTICLE_OBJ) $(PLAYER_OBJ) $(FOOD_OBJ) $(MAIN_OBJ)
	mkdir -p $(BIN_DIR)
	gcc $^ -lraylib -o $@

$(MAIN_OBJ): $(call src, main.c utils.h player.h food.h setup.h)
	gcc -c $< -o $@

$(PARTICLE_OBJ): $(call src, particle.c setup.h particle.h)
	gcc -c $< -o $@

$(PLAYER_OBJ): $(call src, player.c player.h utils.h setup.h)
	gcc -c $< -o $@

$(FOOD_OBJ): $(call src, food.c food.h utils.h setup.h)
	gcc -c $< -o $@

$(UTILS_OBJ): $(call src, utils.c utils.h setup.h)
	gcc -c $< -o $@

clean:
	rm -f $(OUTPUT_DIR)/*.o

purge: 
	rm -rf $(OUTPUT_DIR)

run: $(BIN_NAME)
	./$<

.PHONY: clean purge run
