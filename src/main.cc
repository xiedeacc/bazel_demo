/*******************************************************************************
 * Copyright (c) 2022 Copyright 2022- xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

// #include "gperftools/profiler.h"

#include "glog/logging.h"
#include "src/file_util.h"

int main(int argc, char** argv) {
  // ProfilerStart("bazel_simple_demo_profile");
  LOG(INFO) << "start bazel_simple_demo";
  FileUtil::CompareDirRecursive("/data/backup/code/archive/tencent",
                                "/data3/data/tencent");
  // FileUtil::CompareDirRecursive("/data3/code/tencent",
  // "/data/backup/code/tencent");
  // FileUtil::MergeLfsFile("/data/backup/code/lfs_file",
  // "/data/gitlab_data/lfs-objects");
  // ProfilerStop();
  return 0;
}
