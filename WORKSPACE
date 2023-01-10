workspace(name = "tbox")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "com_grail_bazel_compdb",
    remote = "git@github.com:grailbio/bazel-compilation-database.git",
    tag = "0.5.2",
)

load("@com_grail_bazel_compdb//:deps.bzl", "bazel_compdb_deps")

bazel_compdb_deps()

git_repository(
    name = "rules_cc",
    commit = "2f8c04c04462ab83c545ab14c0da68c3b4c96191",
    remote = "git@github.com:bazelbuild/rules_cc.git",
)

git_repository(
    name = "rules_foreign_cc",
    remote = "git@github.com:bazelbuild/rules_foreign_cc.git",
    tag = "0.8.0",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

git_repository(
    name = "rules_proto",
    remote = "git@github.com:bazelbuild/rules_proto.git",
    tag = "5.3.0-21.7",
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

git_repository(
    name = "com_github_gflags_gflags",
    remote = "git@github.com:gflags/gflags.git",
    tag = "v2.2.2",
)

git_repository(
    name = "com_google_googletest",
    remote = "git@github.com:google/googletest.git",
    tag = "release-1.11.0",
)

git_repository(
    name = "com_google_absl",
    #tag = "20211102.0",
    commit = "fe767217ed2c05ec7d65ca71b42474888f9a64dc",
    remote = "git@github.com:xiedeacc/abseil-cpp.git",
)

git_repository(
    name = "boringssl",
    commit = "56ec9e8ce8fe439a673274f2d8be19f79b09914e",
    remote = "git@github.com:google/boringssl.git",
)

git_repository(
    name = "glog",
    remote = "git@github.com:google/glog.git",
    tag = "v0.6.0",
)

git_repository(
    name = "com_google_protobuf",
    remote = "git@github.com:protocolbuffers/protobuf.git",
    tag = "v3.19.2",
)

git_repository(
    name = "com_github_grpc_grpc",
    remote = "git@github.com:grpc/grpc.git",
    tag = "v1.47.0",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
#load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_deps()
#grpc_extra_deps()

http_archive(
    name = "com_github_nelhage_rules_boost",
    #sha256 = "96e9b631f104b43a53c21c87b01ac538ad6f3b48",
    strip_prefix = "rules_boost-96e9b631f104b43a53c21c87b01ac538ad6f3b48",
    urls = ["https://github.com/nelhage/rules_boost/archive/96e9b631f104b43a53c21c87b01ac538ad6f3b48.tar.gz"],
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()

new_git_repository(
    name = "rapidjson",
    build_file = "@bazel_build_file//bazel:rapidjson.BUILD",
    commit = "8261c1ddf43f10de00fd8c9a67811d1486b2c784",
    remote = "git@github.com:Tencent/rapidjson.git",
)

new_git_repository(
    name = "smhasher",
    build_file = "@bazel_build_file//bazel:smhasher.BUILD",
    commit = "fb0b59ab911126082d33aaedb934cc2f787f4f5a",
    recursive_init_submodules = True,
    remote = "git@github.com:rurban/smhasher.git",
)

http_archive(
    name = "com_github_gperftools_gperftools",
    build_file = "@bazel_build_file//bazel:gperftools.BUILD",
    strip_prefix = "gperftools-2.10",
    urls = ["git@github.com:gperftools/gperftools/releases/download/gperftools-2.10/gperftools-2.10.tar.gz"],
)

bind(
    name = "gperftools",
    actual = "@bazel_build_file//bazel:gperftools",
)

new_git_repository(
    name = "jemalloc",
    build_file = "@bazel_build_file//bazel:jemalloc.BUILD",
    remote = "git@github.com:jemalloc/jemalloc.git",
    tag = "5.3.0",
)

new_git_repository(
    name = "cpplint",
    build_file = "//bazel:cpplint.BUILD",
    remote = "git@github.com:cpplint/cpplint.git",
    tag = "1.6.0",
)
