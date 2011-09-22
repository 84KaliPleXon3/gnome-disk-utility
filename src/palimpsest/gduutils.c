/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2008-2011 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: David Zeuthen <davidz@redhat.com>
 */

#include "config.h"
#include <glib/gi18n.h>

#include "gduutils.h"

gboolean
gdu_utils_drive_treat_as_removable (UDisksDrive  *drive,
                                    UDisksBlock  *block)
{
  gboolean ret = FALSE;
  const gchar *device_file;

  g_return_val_if_fail (UDISKS_IS_DRIVE (drive), FALSE);
  g_return_val_if_fail (UDISKS_IS_BLOCK (block), FALSE);

  if (udisks_drive_get_media_removable (drive))
    {
      ret = TRUE;
      goto out;
    }

  device_file = udisks_block_get_device (block);
  if (g_str_has_prefix (device_file, "/dev/mmcblk"))
    {
      ret = TRUE;
      goto out;
    }

 out:
  return ret;
}
