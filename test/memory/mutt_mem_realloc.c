/**
 * @file
 * Test code for mutt_mem_realloc()
 *
 * @authors
 * Copyright (C) 2019-2023 Richard Russon <rich@flatcap.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define TEST_NO_MAIN
#include "config.h"
#include "acutest.h"
#include <stddef.h>
#include "mutt/lib.h"

void test_mutt_mem_realloc(void)
{
  // void mutt_mem_realloc(void *ptr, size_t size);

  {
    mutt_mem_realloc(NULL, 10);
    TEST_CHECK_(1, "mutt_mem_realloc(NULL, 10)");
  }

  {
    void *ptr = mutt_mem_malloc(128);
    mutt_mem_realloc(&ptr, 256);
    TEST_CHECK_(1, "mutt_mem_realloc(&ptr, 256)");
    TEST_CHECK(ptr != NULL);
    FREE(&ptr);
  }

  {
    void *ptr = mutt_mem_malloc(128);
    mutt_mem_realloc(&ptr, 0);
    TEST_CHECK_(1, "mutt_mem_realloc(&ptr, 0)");
    TEST_CHECK(ptr == NULL);
    FREE(&ptr);
  }
}
