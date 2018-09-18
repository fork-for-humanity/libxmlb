/*
 * Copyright (C) 2018 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#ifndef __XB_SILO_PRIVATE_H__
#define __XB_SILO_PRIVATE_H__

#include "xb-node.h"
#include "xb-silo.h"

/* 32 bytes, native byte order */
typedef struct __attribute__ ((packed)) {
	guint32		magic;
	guint32		version;
	guint8		guid[16];
	guint8		padding1[4];
	guint32		strtab;
} XbSiloHeader;

#define XB_SILO_MAGIC_BYTES		0x624c4d58
#define XB_SILO_VERSION			0x00000002
#define XB_SILO_UNSET			0xffffffff

typedef struct __attribute__ ((packed)) {
	guint8		is_node:1;
	guint8		has_text:1;
	guint8		nr_attrs:6;
	guint32		element_name;	/* ONLY when is_node: from strtab */
	guint32		parent;		/* ONLY when is_node: from 0 */
	guint32		next;		/* ONLY when is_node: from 0 */
	guint32		text;		/* ONLY when is_node && has_text: from strtab */
} XbSiloNode;

typedef struct __attribute__ ((packed)) {
	guint32		attr_name;	/* from strtab */
	guint32		attr_value;	/* from strtab */
} XbSiloAttr;

const gchar	*xb_silo_from_strtab		(XbSilo		*self,
						 guint32	 offset);
XbSiloNode	*xb_silo_get_node		(XbSilo		*self,
						 guint32	 off);
XbSiloAttr	*xb_silo_get_attr		(XbSilo		*self,
						 guint32	 off,
						 guint8		 idx);
guint32		 xb_silo_get_strtab		(XbSilo		*self);
guint32		 xb_silo_get_offset_for_node	(XbSilo		*self,
						 XbSiloNode	*n);
guint8		 xb_silo_node_get_size		(XbSiloNode	*n);
XbSiloNode	*xb_silo_get_sroot		(XbSilo		*self);
XbSiloNode	*xb_silo_node_get_parent	(XbSilo		*self,
						 XbSiloNode	*n);
XbSiloNode	*xb_silo_node_get_next		(XbSilo		*self,
						 XbSiloNode	*n);
XbSiloNode	*xb_silo_node_get_child		(XbSilo		*self,
						 XbSiloNode	*n);
const gchar	*xb_silo_node_get_element	(XbSilo		*self,
						 XbSiloNode	*n);
const gchar	*xb_silo_node_get_text		(XbSilo		*self,
						 XbSiloNode	*n);
const gchar	*xb_silo_node_get_attr		(XbSilo		*self,
						 XbSiloNode	*n,
						 const gchar	*name);
guint		 xb_silo_node_get_depth		(XbSilo		*self,
						 XbSiloNode	*n);
XbNode		*xb_silo_node_create		(XbSilo		*self,
						 XbSiloNode	*sn);

// FIXME xb-silo-export-private.h?
gchar		*xb_silo_export_with_root	(XbSilo		*self,
						 XbNode		*root,
						 XbNodeExportFlags flags,
						 GError		**error);

#endif /* __XB_SILO_PRIVATE_H__ */
