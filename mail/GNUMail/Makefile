# $NetBSD: Makefile,v 1.43 2016/04/11 19:01:55 ryoon Exp $

DISTNAME=	GNUMail-1.2.0
PKGREVISION=	8
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/gnumail/
COMMENT=	GNUstep clone of NeXT's Mail.app application
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

FIX_GNUSTEP_INSTALLATION_DIR= yes
.for dir in Account Advanced Clock Colors Compose Face Filtering	\
	Fonts Import MIME PGP Receiving Sending Viewing
SUBST_FILES.gnustep_installation_dir+=	Bundles/${dir}/GNUmakefile
.endfor

.include "../../mail/Pantomime/buildlink3.mk"
.include "../../misc/Addresses/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
