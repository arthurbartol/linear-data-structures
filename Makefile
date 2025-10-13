CC = clang
CFLAGS = -Wall -Wextra

SRC_DIR = src
TESTS_DIR = tests
BUILD_DIR = build

SRC_FILES = $(SRC_DIR)/*.c
TESTS_SRC_FILES = $(TESTS_DIR)/*.c

# Ensure build dir exists
$(shell mkdir -p $(BUILD_DIR))

# Default target
all: $(BUILD_DIR)/test_dynamic_array $(BUILD_DIR)/test_stack $(BUILD_DIR)/test_queue $(BUILD_DIR)/test_linked_list $(BUILD_DIR)/test_double_linked_list

# Build test binaries
$(BUILD_DIR)/test_dynamic_array: $(SRC_DIR)/dynamic_array.c $(TESTS_DIR)/test_dynamic_array.c
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/test_stack: $(SRC_DIR)/stack.c $(TESTS_DIR)/test_stack.c
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/test_queue:
	@echo "[TODO] Queue test not implemented yet."

$(BUILD_DIR)/test_linked_list:
	@echo "[TODO] Linked list test not implemented yet."

$(BUILD_DIR)/test_double_linked_list:
	@echo "[TODO] Double linked list test not implemented yet."


run-tests: all
	@echo "\n--- Running Dynamic Array Test ---\n"
	@$(BUILD_DIR)/test_dynamic_array
	@echo "\n--- Running Stack Test ---\n"
	@$(BUILD_DIR)/test_stack

clean:
	rm -rf $(BUILD_DIR)

