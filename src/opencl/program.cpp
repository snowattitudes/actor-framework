/******************************************************************************\
 *           ___        __                                                    *
 *          /\_ \    __/\ \                                                   *
 *          \//\ \  /\_\ \ \____    ___   _____   _____      __               *
 *            \ \ \ \/\ \ \ '__`\  /'___\/\ '__`\/\ '__`\  /'__`\             *
 *             \_\ \_\ \ \ \ \L\ \/\ \__/\ \ \L\ \ \ \L\ \/\ \L\.\_           *
 *             /\____\\ \_\ \_,__/\ \____\\ \ ,__/\ \ ,__/\ \__/.\_\          *
 *             \/____/ \/_/\/___/  \/____/ \ \ \/  \ \ \/  \/__/\/_/          *
 *                                          \ \_\   \ \_\                     *
 *                                           \/_/    \/_/                     *
 *                                                                            *
 * Copyright (C) 2011-2013                                                    *
 * Dominik Charousset <dominik.charousset@haw-hamburg.de>                     *
 * Raphael Hiesgen <raphael.hiesgen@haw-hamburg.de>                           *
 *                                                                            *
 * This file is part of libcppa.                                              *
 * libcppa is free software: you can redistribute it and/or modify it under   *
 * the terms of the GNU Lesser General Public License as published by the     *
 * Free Software Foundation, either version 3 of the License                  *
 * or (at your option) any later version.                                     *
 *                                                                            *
 * libcppa is distributed in the hope that it will be useful,                 *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                       *
 * See the GNU Lesser General Public License for more details.                *
 *                                                                            *
 * You should have received a copy of the GNU Lesser General Public License   *
 * along with libcppa. If not, see <http://www.gnu.org/licenses/>.            *
\******************************************************************************/

#include "cppa/opencl/program.hpp"
#include "cppa/opencl/command_dispatcher.hpp"

namespace cppa { namespace opencl {

program::program(const std::string& kernel_source) {
    m_context =
        cppa::detail::singleton_manager::get_command_dispatcher()->m_context;

    cl_int err{0};

    /* create program object from kernel source */
    size_t kernel_source_length = kernel_source.size();
    const char *kernel_source_cstr = kernel_source.c_str();
    m_program.adopt(clCreateProgramWithSource(m_context.get(),
                                              1,
                                              &kernel_source_cstr,
                                              &kernel_source_length,
                                              &err));

    if (err != CL_SUCCESS) {
        throw std::runtime_error("[!!!] clCreateProgramWithSource: '"
                            + get_opencl_error(err)
                            + "'.");
    }

    /* build programm from program object */
    err = clBuildProgram(m_program.get(), 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {
        throw std::runtime_error("[!!!] clBuildProgram: '"
                            + get_opencl_error(err)
                            + "'.");
    }
}

} } // namespace cppa::opencl