/*******************************************************************************
 * Copyright (c) 2022 Copyright 2022- xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#ifndef FILE_UTIL_H_
#define FILE_UTIL_H_

#include <string>

class FileUtil {
 private:
  FileUtil() {}
  virtual ~FileUtil() {}

 public:
  static bool CompareDirRecursive(const std::string &left_dir,
                                  const std::string &right_dir);

  static void MergeLfsFile(const std::string &src_dir,
                           const std::string &dest_dir);

  static bool IsDirectory(const std::string &file_path);

  static bool IsRegularFile(const std::string &file_path);

  static bool FileIsExists(const std::string &file_path);

  static void DoCompare(const std::string &left_file,
                        const std::string &right_file);
};

#endif /* FILE_UTIL_H_ */
