// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// This file contains base classes for fileBrowserPrivate API.

#ifndef CHROME_BROWSER_CHROMEOS_EXTENSIONS_FILE_MANAGER_PRIVATE_API_BASE_H_
#define CHROME_BROWSER_CHROMEOS_EXTENSIONS_FILE_MANAGER_PRIVATE_API_BASE_H_

#include "base/time/time.h"
#include "chrome/browser/extensions/extension_function.h"

namespace file_manager {

// This class adds a logging feature to AsyncExtensionFunction. Logging is
// done when sending the response to JavaScript, using drive::util::Log().
// Async API functions of fileBrowserPrivate should inherit this class.
//
// By default, logging is turned off, hence sub classes should call
// set_log_on_completion(true) to enable it, if they want. However, even if
// the logging is turned off, a warning is emitted when a function call is
// very slow. See the implementation of SendResponse() for details.
class LoggedAsyncExtensionFunction : public AsyncExtensionFunction {
 public:
  LoggedAsyncExtensionFunction();

 protected:
  virtual ~LoggedAsyncExtensionFunction();

  // AsyncExtensionFunction overrides.
  virtual void SendResponse(bool success) OVERRIDE;

  // Sets the logging on completion flag. By default, logging is turned off.
  void set_log_on_completion(bool log_on_completion) {
    log_on_completion_ = log_on_completion;
  }

 private:
  base::Time start_time_;
  bool log_on_completion_;
};

}  // namespace file_manager

#endif  // CHROME_BROWSER_CHROMEOS_EXTENSIONS_FILE_MANAGER_PRIVATE_API_BASE_H_
