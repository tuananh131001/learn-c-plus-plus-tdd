BUILD_DIR := build

.PHONY: build_and_test build test configure clean

build_and_test: build test

configure:
	cmake -S . -B $(BUILD_DIR)

build: configure
	cmake --build $(BUILD_DIR)

test:
	ctest --test-dir $(BUILD_DIR) --output-on-failure

test_verbose:
	ctest --test-dir $(BUILD_DIR) --output-on-failure -V


clean:
	cmake --build $(BUILD_DIR) --target clean
