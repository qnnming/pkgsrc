# $NetBSD: Makefile,v 1.122 2016/09/12 17:22:45 adam Exp $

.include "Makefile.version"

DISTNAME=	cmake-${CMAKE_VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://cmake.org/files/v${CMAKE_API}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	Cross platform make
LICENSE=	modified-bsd

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	bootstrap

BUILD_TARGET=		default_target

CONFIGURE_HAS_MANDIR=	no
CONFIGURE_ARGS+=	--mandir=/${PKGMANDIR}
CONFIGURE_ARGS+=	--docdir=/share/doc/cmake-${CMAKE_API}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--system-libs
# jsoncpp requires cmake to build, so use the one provided with cmake
CONFIGURE_ARGS+=	--no-system-jsoncpp

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"

.if !empty(MAKE_JOBS)
CONFIGURE_ARGS+=	--parallel=${MAKE_JOBS:Q}
.endif

.if ${OPSYS} == "NetBSD" && ${OS_VARIANT} == "Minix"
LDFLAGS+= -lbz2 -llzma

post-extract:
	${CP} ${FILESDIR}/Minix.cmake ${WRKSRC}/Modules/Platform/
.endif # ${OPSYS} == "NetBSD" && ${OS_VARIANT} == "Minix"

PLIST_SUBST+=		CMAKE_API=${CMAKE_API}

# for Source/cmDependsJavaParser.cxx
UNLIMIT_RESOURCES=	datasize

# as of 2.4.6, x11 and fortran tests fail in pkgsrc
TEST_TARGET=		test

SUBST_CLASSES+=		cmake
SUBST_STAGE.cmake=	pre-configure
SUBST_MESSAGE.cmake=	Fixing LOCALBASE and X11 paths.
SUBST_FILES.cmake+=	Modules/FindX11.cmake
SUBST_FILES.cmake+=	Modules/Platform/UnixPaths.cmake
SUBST_VARS.cmake=	LOCALBASE X11BASE

SUBST_CLASSES+=		flags
SUBST_STAGE.flags=	pre-configure
SUBST_MESSAGE.flags=	Fixing compiler flags.
SUBST_FILES.flags=	Modules/Compiler/*.cmake
SUBST_SED.flags=	-e 's,-O.,,'

pre-configure:
	${RM} -f ${WRKSRC}/Modules/*.orig ${WRKSRC}/Modules/Platform/*.orig
	${LN} -f ${WRKSRC}/Modules/Platform/OpenBSD.cmake ${WRKSRC}/Modules/Platform/MirBSD.cmake
.for lang in C CXX Fortran
	${LN} -f ${WRKSRC}/Modules/Platform/SunOS-GNU-${lang}.cmake \
	    ${WRKSRC}/Modules/Platform/SunOS-Clang-${lang}.cmake
.endfor

INCOMPAT_CURSES=	NetBSD-[0-7].*-*

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=3.0.0
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
