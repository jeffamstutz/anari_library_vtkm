// Copyright 2022 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "VTKmDeviceGlobalState.h"
#include "vtkm_device_math.h"
// helium
#include <helium/BaseObject.h>
#include <helium/utility/ChangeObserverPtr.h>
// std
#include <string_view>

namespace vtkm_device {

struct Object : public helium::BaseObject
{
  Object(ANARIDataType type, VTKmDeviceGlobalState *s);
  virtual ~Object() = default;

  bool getProperty(const std::string_view &name,
      ANARIDataType type,
      void *ptr,
      uint32_t flags) override;

  void commit() override;

  bool isValid() const override;

  VTKmDeviceGlobalState *deviceState() const;

  void printParameters();
};

struct UnknownObject : public Object
{
  UnknownObject(ANARIDataType type, VTKmDeviceGlobalState *s);
  ~UnknownObject() override;
  bool isValid() const override;
};

} // namespace vtkm_device

VTKM_ANARI_TYPEFOR_SPECIALIZATION(vtkm_device::Object *, ANARI_OBJECT);
