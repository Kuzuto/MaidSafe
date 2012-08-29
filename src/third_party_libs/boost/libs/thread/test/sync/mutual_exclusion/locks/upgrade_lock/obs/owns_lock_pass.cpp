//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Copyright (C) 2011 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// <boost/thread/locks.hpp>

// template <class Mutex> class upgrade_lock;

// bool owns_lock() const;

#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/detail/lightweight_test.hpp>

boost::shared_mutex m;

int main()
{
  boost::upgrade_lock<boost::shared_mutex> lk0;
  BOOST_TEST(lk0.owns_lock() == false);
  boost::upgrade_lock<boost::shared_mutex> lk1(m);
  BOOST_TEST(lk1.owns_lock() == true);
  lk1.unlock();
  BOOST_TEST(lk1.owns_lock() == false);


  return boost::report_errors();
}

