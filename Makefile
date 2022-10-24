.PHONY: xproj
xproj:
	rm -rf build
	mkdir build
	cd build && cmake -G Xcode .. && open cdps.xcodeproj
	

.PHONY: format
format:
	find . -iname "*.h" -or -iname "*.hpp" -or -iname "*.cpp" | xargs clang-format -i
