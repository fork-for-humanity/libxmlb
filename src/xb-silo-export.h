/*
 * Copyright (C) 2018 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#ifndef __XB_SILO_EXPORT_H
#define __XB_SILO_EXPORT_H

#include <glib-object.h>

#include "xb-node.h"
#include "xb-silo.h"

G_BEGIN_DECLS

gchar		*xb_silo_export			(XbSilo		*self,
						 XbNodeExportFlags flags,
						 GError		**error);
gboolean	 xb_silo_export_file		(XbSilo		*self,
						 GFile		*file,
						 XbNodeExportFlags flags,
						 GCancellable	*cancellable,
						 GError		**error);

G_END_DECLS

#endif /* __XB_SILO_EXPORT_H */
