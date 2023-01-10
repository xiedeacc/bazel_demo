/*******************************************************************************
 * Copyright (c) 2022 Copyright 2022- xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#include "src/file_util.h"

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string>

#include "boost/filesystem.hpp"
#include "boost/filesystem/directory.hpp"
#include "glog/logging.h"

using std::string;

bool FileUtil::IsDirectory(const string &file_path) {
  return boost::filesystem::is_directory(file_path);
}

bool FileUtil::IsRegularFile(const string &file_path) {
  return boost::filesystem::is_regular_file(file_path);
}

bool FileUtil::FileIsExists(const string &file_path) {
  return boost::filesystem::exists(file_path);
}

void FileUtil::DoCompare(const string &left_file, const string &right_file) {
  uintmax_t l_size = boost::filesystem::file_size(left_file);
  uintmax_t r_size = boost::filesystem::file_size(right_file);
  if (l_size != r_size) {
    LOG(ERROR) << left_file << " " << right_file << ", size not equal!";
  }
}

bool FileUtil::CompareDirRecursive(const string &left_dir,
                                   const string &right_dir) {
  boost::filesystem::path l_path(left_dir);
  boost::filesystem::directory_iterator end_iter;
  for (boost::filesystem::directory_iterator iter(l_path); iter != end_iter;
       ++iter) {
    if (iter->path().filename().string() == "." ||
        iter->path().filename().string() == "..") {
      continue;
    }

    string file_name = iter->path().filename().string();
    string left_full_path = left_dir + "/" + file_name;
    string right_full_path = right_dir + "/" + file_name;

    // LOG(INFO) << left_full_path << " " << right_full_path;
    // if (left_full_path == "/data/backup/code/tencent") {
    //  continue;
    // }

    if (!FileIsExists(right_full_path)) {
      LOG(ERROR) << left_full_path << " " << right_full_path
                 << ", right not exists!";
      continue;
    }

    if ((IsDirectory(left_full_path) && !IsDirectory(right_full_path)) ||
        (!IsDirectory(left_full_path) && IsDirectory(right_full_path))) {
      LOG(ERROR) << left_full_path << " " << right_full_path
                 << ", type different!";
      continue;
    }

    if (IsDirectory(left_full_path) && IsDirectory(right_full_path)) {
      CompareDirRecursive(left_full_path, right_full_path);
    } else if (!IsRegularFile(left_full_path)) {
      // LOG(INFO) << left_full_path << " " << right_full_path;
      continue;
    } else {
      DoCompare(left_full_path, right_full_path);
    }
  }

  return true;
}

void FileUtil::MergeLfsFile(const string &src_dir, const string &dest_dir) {
  boost::filesystem::path l_path(src_dir);
  boost::filesystem::directory_iterator end_iter;
  for (boost::filesystem::directory_iterator iter(l_path); iter != end_iter;
       ++iter) {
    if (iter->path().filename().string() == "." ||
        iter->path().filename().string() == "..") {
      continue;
    }

    string file_name = iter->path().filename().string();
    string dest_dir_path =
        dest_dir + "/" + file_name.substr(0, 2) + "/" + file_name.substr(2, 2);
    string dest_file_path = dest_dir_path + "/" + file_name.substr(4);

    if (!FileIsExists(dest_dir_path)) {
      boost::filesystem::create_directory(dest_dir_path);
    }
    if (FileIsExists(dest_file_path)) {
      continue;
    }
    LOG(INFO) << "cp " << iter->path() << " to " << dest_file_path;
    boost::filesystem::copy_file(iter->path().string(), dest_file_path);
  }
}
