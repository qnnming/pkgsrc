# $NetBSD: Makefile,v 1.36 2016/08/03 10:23:12 adam Exp $

DISTNAME=	pitivi-0.15.2
PKGREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pitivi/0.15/}
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pitivi/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pitivi.org/
COMMENT=	Video editor

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

CONFIGURE_ENV+=	ac_cv_path_PYTHON=${PYTHONBIN}
REPLACE_PYTHON=	bin/pitivi.in
PYTHON_VERSIONED_DEPENDENCIES=	cairo
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-gtk2, py-gstreamer0.10

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-gnonlin/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
