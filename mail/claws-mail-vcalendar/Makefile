# $NetBSD: Makefile,v 1.55 2016/09/19 13:04:23 wiz Exp $
#

PLUGIN_NAME=    vcalendar
PKGREVISION= 1
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enable vCalendar message handling

USE_TOOLS+=	perl

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin
PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
