rm -rf build && mkdir build \
    && cd build && cmake .. \
    && make -j && ./kalman_test
