# $NetBSD: Makefile,v 1.45 2016/08/03 10:23:26 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-netload-plugin-1.2.99
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-netload-plugin/1.2/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-netload-plugin
COMMENT=	Xfce network load plugin

LDFLAGS.SunOS+=	-lnsl

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
