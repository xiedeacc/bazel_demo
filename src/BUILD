load("//tools:cpplint.bzl", "cpplint")
load("//tools:build.bzl", "cc_test")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "file_util",
    srcs = ["file_util.cc"],
    hdrs = ["file_util.h"],
    linkstatic = 1,
    deps = [
        "@boost//:filesystem",
        "@boost//:smart_ptr",
        "@glog",
    ],
)

cc_binary(
    name = "ranking",
    srcs = ["ranking.cc"],
    defines = [
        "BOOST_THREAD_BUILD_LIB=1",
        "BOOST_THREAD_PLATFORM_PTHREAD",
        "BOOST_THREAD_POSIX",
        "BOOST_THREAD_USES_CHRONO",
    ],
    linkopts = [
        "-lpthread",
    ],
    linkstatic = 1,
    deps = [
        ":file_util",
        "@boost//:algorithm",
        "@boost//:filesystem",
        #"@com_github_gperftools_gperftools//:gperftools",
        "@glog",
    ],
)

cc_test(
    name = "file_util_test",
    srcs = ["file_util_test.cc"],
    data = [
        "//test_data:exported_testdata",
    ],
    deps = [
        ":file_util",
    ],
)

cpplint()
