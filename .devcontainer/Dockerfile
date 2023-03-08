FROM ubuntu:22.04

# Meta-data:
LABEL maintainer="Xelerezex" \
      description="Default C++ development environment" \
      version="0.0.1"

# ?
ARG DEBIAN_FRONTEND=noninteractive

# Setup timezone
RUN apt-get update -y
RUN apt-get install -y tzdata

ENV TZ="Europe/Moscow"

# Flags for packages installation
ARG INST_FLAGS="-y --no-install-recommends"

# Main installations:
RUN apt-get install ${INST_FLAGS} aptitude 
RUN apt-get install ${INST_FLAGS} pkg-config
RUN apt-get install ${INST_FLAGS} wget 
RUN apt-get install ${INST_FLAGS} gnupg
RUN apt-get install ${INST_FLAGS} apt-transport-https
RUN apt-get install ${INST_FLAGS} build-essential
RUN apt-get install ${INST_FLAGS} g++
RUN apt-get install ${INST_FLAGS} libc++-dev
RUN apt-get install ${INST_FLAGS} git
RUN apt-get install ${INST_FLAGS} make
RUN apt-get install ${INST_FLAGS} cmake
RUN apt-get install ${INST_FLAGS} ninja-build
RUN apt-get install ${INST_FLAGS} tar
RUN apt-get install ${INST_FLAGS} curl
RUN apt-get install ${INST_FLAGS} unzip
RUN apt-get install ${INST_FLAGS} clang
RUN apt-get install ${INST_FLAGS} lld
RUN apt-get install ${INST_FLAGS} lldb
RUN apt-get install ${INST_FLAGS} valgrind
RUN apt-get install ${INST_FLAGS} doxygen
RUN apt-get install ${INST_FLAGS} ca-certificates
RUN apt-get install ${INST_FLAGS} locales
# Dependecies for GTests
RUN apt-get install ${INST_FLAGS} libgtest-dev
RUN apt-get install ${INST_FLAGS} libgmock-dev
RUN apt-get install ${INST_FLAGS} libtbb-dev
RUN apt-get install ${INST_FLAGS} libpcsclite-dev
# Dependecies for Sublime Merge
RUN apt-get install ${INST_FLAGS} ffmpeg 
RUN apt-get install ${INST_FLAGS} libsm6 
RUN apt-get install ${INST_FLAGS} libxext6

# Path to google test library:
ENV GTEST_PATH="/usr/src/googletest"

# Build GTest library:
RUN cd /
RUN mkdir ${GTEST_PATH}/build
RUN cmake -S ${GTEST_PATH} -B ${GTEST_PATH}/build
RUN cmake --build ${GTEST_PATH}/build --target install
RUN cp ${GTEST_PATH}/build/lib/* /usr/lib
RUN rm -rf ${GTEST_PATH}/build

# Install sublime-merge:
RUN wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | apt-key add -
RUN wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg \ 
    | gpg --dearmor \
    | tee /etc/apt/trusted.gpg.d/sublimehq-archive.gpg > /dev/null
RUN echo "deb https://download.sublimetext.com/ apt/stable/" \
    | tee /etc/apt/sources.list.d/sublime-text.list
RUN apt-get update
RUN apt-get install -y sublime-merge

# Regular commands:
RUN apt-get autoclean 
RUN apt-get autoremove 
RUN apt-get clean
RUN rm -rf /var/lib/apt/lists/*
RUN localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8

# Setup localization
ENV LANG en_US.utf8
