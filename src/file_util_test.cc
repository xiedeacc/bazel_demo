/*******************************************************************************
 * Copyright (c) 2022 Copyright 2022- xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#include "src/file_util.h"

#include "glog/logging.h"
#include "gtest/gtest.h"

using std::string;

TEST(FileUtilTest, IsDirectory) {
  ASSERT_TRUE(FileUtil::IsDirectory("test_data/directory"));
  ASSERT_FALSE(FileUtil::IsDirectory("test_data/file"));
}

TEST(FileUtilTest, FileIsExists) {
  ASSERT_FALSE(FileUtil::FileIsExists("test_data/not_exists"));
  ASSERT_TRUE(FileUtil::FileIsExists("test_data/file"));
}

TEST(FileUtilTest, DoCompare) {
  FileUtil::DoCompare("test_data/file_sha256_1", "test_data/file_sha256_2");
}

// TEST(FileUtilTest, StringSha256) {
// char sha256_value[65];
// string str = "xiedeacc";
// FileUtil::StringSha256(str, sha256_value);
// ASSERT_EQ(
// strcmp(
// sha256_value,
// "872bea6606461caa9c5272e2494338b7e07cc2bfc3aa19b3a06613f6557664ac"),
// 0);
// }

// TEST(FileUtilTest, FileSha256) {
// char sha256_value[65];
//// NOTICE: vim will add a new line character at end of line automatic
// FileUtil::FileSha256("test_data/file_sha256_1", sha256_value);

// ASSERT_EQ(
// strcmp(
// sha256_value,
// "872bea6606461caa9c5272e2494338b7e07cc2bfc3aa19b3a06613f6557664ac"),
// 0);
// }
