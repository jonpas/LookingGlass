/**
 * Looking Glass
 * Copyright © 2017-2025 The Looking Glass Authors
 * https://looking-glass.io
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 59
 * Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#pragma once

#include <Windows.h>
#include <SetupAPI.h>
#include <vector>

class CIVSHMEM
{
private:
  struct IVSHMEMData
  {
    SP_DEVINFO_DATA devInfoData;
    DWORD64         busAddr;
  };

  std::vector<struct IVSHMEMData> m_devices;
  HANDLE m_handle = INVALID_HANDLE_VALUE;
  size_t m_size   = 0;
  void * m_mem    = nullptr;

public:
  CIVSHMEM();
  ~CIVSHMEM();

  bool Init();
  bool Open();
  void Close();

  size_t GetSize() { return m_size; }
  void * GetMem () { return m_mem;  }
};

