/*
 * Copyright 2015-2016 Tobias Waldekranz <tobias@waldekranz.com>
 *
 * This file is part of ply.
 *
 * ply is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, under the terms of version 2 of the
 * License.
 *
 * ply is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ply.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <linux/bpf.h>

#define LOG_BUF_SIZE 0x20000

extern char bpf_log_buf[LOG_BUF_SIZE];

int bpf_prog_load(const struct bpf_insn *insns, int insn_cnt);

int bpf_map_create(enum bpf_map_type type, int key_sz, int val_sz, int entries);

int bpf_map_lookup(int fd, void *key, void *val);
int bpf_map_update(int fd, void *key, void *val, int flags);
int bpf_map_delete(int fd, void *key);
int bpf_map_next  (int fd, void *key, void *next_key);
