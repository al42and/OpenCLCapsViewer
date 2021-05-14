/*
*
* OpenCL hardware capability viewer
*
* Copyright (C) 2021 by Sascha Willems (www.saschawillems.de)
*
* This code is free software, you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License version 3 as published by the Free Software Foundation.
*
* Please review the following information to ensure the GNU Lesser
* General Public License version 3 requirements will be met:
* http://opensource.org/licenses/lgpl-3.0.html
*
* The code is distributed WITHOUT ANY WARRANTY; without even the
* implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE.  See the GNU LGPL 3.0 for more details.
*
*/

#pragma once

#include "CL/cl.h"
#include "CL/cl_ext.h"
#include <sstream>
#include <QString>

enum class clValueType {
	cl_bool,
	cl_char,
	cl_command_queue_properties,
	cl_device_atomic_capabilities,
	cl_device_device_enqueue_capabilities,
	cl_device_exec_capabilities,
	cl_device_fp_config,
	cl_device_local_mem_type,
	cl_device_mem_cache_type,
	cl_device_type,
	cl_size_t,
	cl_uchar,
	cl_uint,
	cl_ulong,
	cl_version,
	special
};

namespace utils
{
	inline QString clVersionString(cl_version version)
	{
		std::stringstream ss;
		ss << CL_VERSION_MAJOR(version) << "." << CL_VERSION_MINOR(version) << "." << CL_VERSION_PATCH(version);
		QString res = QString::fromStdString(ss.str());
		return res;
	}


	inline QString deviceTypeString(const cl_device_type type)
	{
		switch (type)
		{
#define STR(r) case CL_DEVICE_TYPE_##r: return #r
			STR(DEFAULT);
			STR(CPU);
			STR(GPU);
			STR(ACCELERATOR);
			STR(CUSTOM);
#undef STR
		default: return "?";
		}
	}

	inline QString deviceInfoString(const cl_device_info info)
	{
		switch (info)
		{
#define STR(r) case CL_##r: return #r
			STR(DEVICE_TYPE);
			STR(DEVICE_VENDOR_ID);
			STR(DEVICE_MAX_COMPUTE_UNITS);
			STR(DEVICE_MAX_WORK_ITEM_DIMENSIONS);
			STR(DEVICE_MAX_WORK_GROUP_SIZE);
			STR(DEVICE_MAX_WORK_ITEM_SIZES);
			STR(DEVICE_PREFERRED_VECTOR_WIDTH_CHAR);
			STR(DEVICE_PREFERRED_VECTOR_WIDTH_SHORT);
			STR(DEVICE_PREFERRED_VECTOR_WIDTH_INT);
			STR(DEVICE_PREFERRED_VECTOR_WIDTH_LONG);
			STR(DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT);
			STR(DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE);
			STR(DEVICE_MAX_CLOCK_FREQUENCY);
			STR(DEVICE_ADDRESS_BITS);
			STR(DEVICE_MAX_READ_IMAGE_ARGS);
			STR(DEVICE_MAX_WRITE_IMAGE_ARGS);
			STR(DEVICE_MAX_MEM_ALLOC_SIZE);
			STR(DEVICE_IMAGE2D_MAX_WIDTH);
			STR(DEVICE_IMAGE2D_MAX_HEIGHT);
			STR(DEVICE_IMAGE3D_MAX_WIDTH);
			STR(DEVICE_IMAGE3D_MAX_HEIGHT);
			STR(DEVICE_IMAGE3D_MAX_DEPTH);
			STR(DEVICE_IMAGE_SUPPORT);
			STR(DEVICE_MAX_PARAMETER_SIZE);
			STR(DEVICE_MAX_SAMPLERS);
			STR(DEVICE_MEM_BASE_ADDR_ALIGN);
			STR(DEVICE_MIN_DATA_TYPE_ALIGN_SIZE);
			STR(DEVICE_SINGLE_FP_CONFIG);
			STR(DEVICE_GLOBAL_MEM_CACHE_TYPE);
			STR(DEVICE_GLOBAL_MEM_CACHELINE_SIZE);
			STR(DEVICE_GLOBAL_MEM_CACHE_SIZE);
			STR(DEVICE_GLOBAL_MEM_SIZE);
			STR(DEVICE_MAX_CONSTANT_BUFFER_SIZE);
			STR(DEVICE_MAX_CONSTANT_ARGS);
			STR(DEVICE_LOCAL_MEM_TYPE);
			STR(DEVICE_LOCAL_MEM_SIZE);
			STR(DEVICE_ERROR_CORRECTION_SUPPORT);
			STR(DEVICE_PROFILING_TIMER_RESOLUTION);
			STR(DEVICE_ENDIAN_LITTLE);
			STR(DEVICE_AVAILABLE);
			STR(DEVICE_COMPILER_AVAILABLE);
			STR(DEVICE_EXECUTION_CAPABILITIES);
			STR(DEVICE_QUEUE_ON_HOST_PROPERTIES);
			STR(DEVICE_NAME);
			STR(DEVICE_VENDOR);
			STR(DRIVER_VERSION);
			STR(DEVICE_PROFILE);
			STR(DEVICE_VERSION);
			STR(DEVICE_EXTENSIONS);
			STR(DEVICE_PLATFORM);
			STR(DEVICE_DOUBLE_FP_CONFIG);
			STR(DEVICE_PREFERRED_VECTOR_WIDTH_HALF);
			STR(DEVICE_HOST_UNIFIED_MEMORY);
			STR(DEVICE_NATIVE_VECTOR_WIDTH_CHAR);
			STR(DEVICE_NATIVE_VECTOR_WIDTH_SHORT);
			STR(DEVICE_NATIVE_VECTOR_WIDTH_INT);
			STR(DEVICE_NATIVE_VECTOR_WIDTH_LONG);
			STR(DEVICE_NATIVE_VECTOR_WIDTH_FLOAT);
			STR(DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE);
			STR(DEVICE_NATIVE_VECTOR_WIDTH_HALF);
			STR(DEVICE_OPENCL_C_VERSION);
			STR(DEVICE_LINKER_AVAILABLE);
			STR(DEVICE_BUILT_IN_KERNELS);
			STR(DEVICE_IMAGE_MAX_BUFFER_SIZE);
			STR(DEVICE_IMAGE_MAX_ARRAY_SIZE);
			STR(DEVICE_PARENT_DEVICE);
			STR(DEVICE_PARTITION_MAX_SUB_DEVICES);
			STR(DEVICE_PARTITION_PROPERTIES);
			STR(DEVICE_PARTITION_AFFINITY_DOMAIN);
			STR(DEVICE_PARTITION_TYPE);
			STR(DEVICE_REFERENCE_COUNT);
			STR(DEVICE_PREFERRED_INTEROP_USER_SYNC);
			STR(DEVICE_PRINTF_BUFFER_SIZE);
			STR(DEVICE_IMAGE_PITCH_ALIGNMENT);
			STR(DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT);
			STR(DEVICE_MAX_READ_WRITE_IMAGE_ARGS);
			STR(DEVICE_MAX_GLOBAL_VARIABLE_SIZE);
			STR(DEVICE_QUEUE_ON_DEVICE_PROPERTIES);
			STR(DEVICE_QUEUE_ON_DEVICE_PREFERRED_SIZE);
			STR(DEVICE_QUEUE_ON_DEVICE_MAX_SIZE);
			STR(DEVICE_MAX_ON_DEVICE_QUEUES);
			STR(DEVICE_MAX_ON_DEVICE_EVENTS);
			STR(DEVICE_SVM_CAPABILITIES);
			STR(DEVICE_GLOBAL_VARIABLE_PREFERRED_TOTAL_SIZE);
			STR(DEVICE_MAX_PIPE_ARGS);
			STR(DEVICE_PIPE_MAX_ACTIVE_RESERVATIONS);
			STR(DEVICE_PIPE_MAX_PACKET_SIZE);
			STR(DEVICE_PREFERRED_PLATFORM_ATOMIC_ALIGNMENT);
			STR(DEVICE_PREFERRED_GLOBAL_ATOMIC_ALIGNMENT);
			STR(DEVICE_PREFERRED_LOCAL_ATOMIC_ALIGNMENT);
			STR(DEVICE_IL_VERSION);
			STR(DEVICE_MAX_NUM_SUB_GROUPS);
			STR(DEVICE_SUB_GROUP_INDEPENDENT_FORWARD_PROGRESS);
			STR(DEVICE_NUMERIC_VERSION);
			STR(DEVICE_EXTENSIONS_WITH_VERSION);
			STR(DEVICE_ILS_WITH_VERSION);
			STR(DEVICE_BUILT_IN_KERNELS_WITH_VERSION);
			STR(DEVICE_ATOMIC_MEMORY_CAPABILITIES);
			STR(DEVICE_ATOMIC_FENCE_CAPABILITIES);
			STR(DEVICE_NON_UNIFORM_WORK_GROUP_SUPPORT);
			STR(DEVICE_OPENCL_C_ALL_VERSIONS);
			STR(DEVICE_PREFERRED_WORK_GROUP_SIZE_MULTIPLE);
			STR(DEVICE_WORK_GROUP_COLLECTIVE_FUNCTIONS_SUPPORT);
			STR(DEVICE_GENERIC_ADDRESS_SPACE_SUPPORT);
			STR(DEVICE_OPENCL_C_FEATURES);
			STR(DEVICE_DEVICE_ENQUEUE_CAPABILITIES);
			STR(DEVICE_PIPE_SUPPORT);
			STR(DEVICE_LATEST_CONFORMANCE_VERSION_PASSED);
			// cl_nv_device_attribute_query 
			STR(DEVICE_COMPUTE_CAPABILITY_MAJOR_NV);
			STR(DEVICE_COMPUTE_CAPABILITY_MINOR_NV);
			STR(DEVICE_REGISTERS_PER_BLOCK_NV);
			STR(DEVICE_WARP_SIZE_NV);
			STR(DEVICE_GPU_OVERLAP_NV);
			STR(DEVICE_KERNEL_EXEC_TIMEOUT_NV);
			STR(DEVICE_INTEGRATED_MEMORY_NV);
			// cl_khr_device_uuid
			STR(DEVICE_UUID_KHR);
			STR(DRIVER_UUID_KHR);
			STR(DEVICE_LUID_VALID_KHR);
			STR(DEVICE_LUID_KHR);
			STR(DEVICE_NODE_MASK_KHR);
#undef STR
		default: return "?";
		}
	}

	inline QString platformInfoString(const cl_platform_info info)
	{
		switch (info)
		{
#define STR(r) case CL_##r: return #r
			STR(PLATFORM_PROFILE);
			STR(PLATFORM_VERSION);
			STR(PLATFORM_NAME);
			STR(PLATFORM_VENDOR);
			STR(PLATFORM_EXTENSIONS);
			STR(PLATFORM_HOST_TIMER_RESOLUTION);
			STR(PLATFORM_NUMERIC_VERSION);
			STR(PLATFORM_EXTENSIONS_WITH_VERSION);
			// cl_khr_icd
			STR(PLATFORM_ICD_SUFFIX_KHR);
#undef STR
		default: return "?";
		}
	}

}