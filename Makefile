BUILD_DEPS += Makefile
BUILD_DEPS += CMakeLists.txt

IOS_XCODEBUILD_LIB_DEVICE = xcodebuild \
	-target cdps \
	-arch arm64 \
	-configuration Release \
	-sdk iphoneos \

IOS_XCODEBUILD_LIB_SIMULATOR = xcodebuild \
	-target cdps \
	-arch x86_64 \
	-configuration Release \
	-sdk iphonesimulator \

IOS_LIB_COMBINE = build/ios/combine
$(IOS_LIB_COMBINE): $(BUILD_DEPS)
	mkdir -p $(IOS_LIB_COMBINE)
	cd $(IOS_LIB_COMBINE) && (cmake -G Xcode ../../../ \
		-DCMAKE_SYSTEM_PROCESSOR=arm64 \
		-DCMAKE_OSX_ARCHITECTURES=arm64 \
	)

OUTPUT_LIBS = output/libs
OUTPUT_HEADERS = output/headers

.PHONY: ios-lib-combine
ios-lib-combine: $(IOS_LIB_COMBINE)
	set -o pipefail && cd $(IOS_LIB_COMBINE) && $(IOS_XCODEBUILD_LIB_DEVICE) && $(IOS_XCODEBUILD_LIB_SIMULATOR)
	mkdir -p $(OUTPUT_LIBS) && mkdir -p $(OUTPUT_HEADERS) && (lipo -create \
		build/ios/combine/src/cdps/Release-iphoneos/libcdps.a \
		build/ios/combine/src/cdps/Release-iphonesimulator/libcdps.a \
		-output $(OUTPUT_LIBS)/libcdps.a \
		&& cp src/cdps/*.h $(OUTPUT_HEADERS) \
		&& lipo -info $(OUTPUT_LIBS)/libcdps.a \
	)

.PHONY: xproj
xproj:
	rm -rf build
	mkdir build
	cd build && cmake -G Xcode .. && open cdps.xcodeproj

.PHONY: format
format:
	find . -iname "*.h" -or -iname "*.hpp" -or -iname "*.cpp" | xargs clang-format -i
