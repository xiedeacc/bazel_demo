workspace(name = "bazel_demo")

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
    name = "glog",
    remote = "git@github.com:google/glog.git",
    tag = "v0.6.0",
)

http_archive(
    name = "com_github_nelhage_rules_boost",
    #sha256 = "96e9b631f104b43a53c21c87b01ac538ad6f3b48",
    strip_prefix = "rules_boost-96e9b631f104b43a53c21c87b01ac538ad6f3b48",
    urls = ["https://github.com/nelhage/rules_boost/archive/96e9b631f104b43a53c21c87b01ac538ad6f3b48.tar.gz"],
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()

http_archive(
    name = "gperftools",
    build_file = "//bazel:gperftools.BUILD",
    strip_prefix = "gperftools-2.10",
    urls = ["https://github.com/gperftools/gperftools/releases/download/gperftools-2.10/gperftools-2.10.tar.gz"],
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
