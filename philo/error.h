/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:06:27 by emgul             #+#    #+#             */
/*   Updated: 2024/09/10 15:06:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERR_EPERM       "Operation not permitted"
#define ERR_ENOENT      "No such file or directory"
#define ERR_ESRCH       "No such process"
#define ERR_EINTR       "Interrupted system call"
#define ERR_EIO         "I/O error"
#define ERR_ENXIO       "No such device or address"
#define ERR_E2BIG       "Argument list too long"
#define ERR_ENOEXEC     "Exec format error"
#define ERR_EBADF       "Bad file number"
#define ERR_ECHILD      "No child processes"
#define ERR_EAGAIN      "Try again"
#define ERR_ENOMEM      "Out of memory"
#define ERR_EACCES      "Permission denied"
#define ERR_EFAULT      "Bad address"
#define ERR_ENOTBLK     "Block device required"
#define ERR_EBUSY       "Device or resource busy"
#define ERR_EEXIST      "File exists"
#define ERR_EXDEV       "Cross-device link"
#define ERR_ENODEV      "No such device"
#define ERR_ENOTDIR     "Not a directory"
#define ERR_EISDIR      "Is a directory"
#define ERR_EINVAL      "Invalid argument"
#define ERR_ENFILE      "File table overflow"
#define ERR_EMFILE      "Too many open files"
#define ERR_ENOTTY      "Not a typewriter"
#define ERR_ETXTBSY     "Text file busy"
#define ERR_EFBIG       "File too large"
#define ERR_ENOSPC      "No space left on device"
#define ERR_ESPIPE      "Illegal seek"
#define ERR_EROFS       "Read-only file system"
#define ERR_EMLINK      "Too many links"
#define ERR_EPIPE       "Broken pipe"
#define ERR_EDOM        "Math argument out of domain of func"
#define ERR_ERANGE      "Math result not representable"

#define ERR_EBFONT       "Bad font file format"
#define ERR_ENOSTR       "Device not a stream"
#define ERR_ENODATA      "No data available"
#define ERR_ETIME        "Timer expired"
#define ERR_ENOSR        "Out of streams resources"
#define ERR_ENONET       "Machine is not on the network"
#define ERR_ENOPKG       "Package not installed"
#define ERR_EREMOTE      "Object is remote"
#define ERR_ENOLINK      "Link has been severed"
#define ERR_EADV         "Advertise error"
#define ERR_ESRMNT       "Srmount error"
#define ERR_ECOMM        "Communication error on send"
#define ERR_EPROTO       "Protocol error"
#define ERR_EMULTIHOP    "Multihop attempted"
#define ERR_EDOTDOT      "RFS specific error"
#define ERR_EBADMSG      "Not a data message"
#define ERR_EOVERFLOW    "Value too large for defined data type"
#define ERR_ENOTUNIQ     "Name not unique on network"
#define ERR_EBADFD       "File descriptor in bad state"
#define ERR_EREMCHG      "Remote address changed"
#define ERR_ELIBACC      "Can not access a needed shared library"
#define ERR_ELIBBAD      "Accessing a corrupted shared library"
#define ERR_ELIBSCN      ".lib section in a.out corrupted"
#define ERR_ELIBMAX      "Attempting to link in too many shared libraries"
#define ERR_ELIBEXEC     "Cannot exec a shared library directly"
#define ERR_EILSEQ       "Illegal byte sequence"
#define ERR_ERESTART     "Interrupted system call should be restarted"
#define ERR_ESTRPIPE     "Streams pipe error"
#define ERR_EUSERS       "Too many users"
#define ERR_ENOTSOCK     "Socket operation on non-socket"
#define ERR_EDESTADDRREQ "Destination address required"
#define ERR_EMSGSIZE     "Message too long"
#define ERR_EPROTOTYPE   "Protocol wrong type for socket"
#define ERR_ENOPROTOOPT  "Protocol not available"
#define ERR_EPROTONOSUPPORT "Protocol not supported"
#define ERR_ESOCKTNOSUPPORT "Socket type not supported"
#define ERR_EOPNOTSUPP   "Operation not supported on transport endpoint"
#define ERR_EPFNOSUPPORT "Protocol family not supported"
#define ERR_EAFNOSUPPORT "Address family not supported by protocol"
#define ERR_EADDRINUSE   "Address already in use"
#define ERR_EADDRNOTAVAIL "Cannot assign requested address"
#define ERR_ENETDOWN     "Network is down"
#define ERR_ENETUNREACH  "Network is unreachable"
#define ERR_ENETRESET    "Network dropped connection because of reset"
#define ERR_ECONNABORTED "Software caused connection abort"
#define ERR_ECONNRESET   "Connection reset by peer"
#define ERR_ENOBUFS      "No buffer space available"
#define ERR_EISCONN      "Transport endpoint is already connected"
#define ERR_ENOTCONN     "Transport endpoint is not connected"
#define ERR_ESHUTDOWN    "Cannot send after transport endpoint shutdown"
#define ERR_ETOOMANYREFS "Too many references: cannot splice"
#define ERR_ETIMEDOUT    "Connection timed out"
#define ERR_ECONNREFUSED "Connection refused"
#define ERR_EHOSTDOWN    "Host is down"
#define ERR_EHOSTUNREACH "No route to host"
#define ERR_EALREADY     "Operation already in progress"
#define ERR_EINPROGRESS  "Operation now in progress"
#define ERR_ESTALE       "Stale file handle"
#define ERR_EUCLEAN      "Structure needs cleaning"
#define ERR_ENOTNAM      "Not a XENIX named type file"
#define ERR_ENAVAIL      "No XENIX semaphores available"
#define ERR_EISNAM       "Is a named type file"
#define ERR_EREMOTEIO    "Remote I/O error"
#define ERR_EDQUOT       "Quota exceeded"

#define ERR_EDEADLK       "Resource deadlock would occur"
#define ERR_ENAMETOOLONG  "File name too long"
#define ERR_ENOLCK        "No record locks available"

#define ERR_UNKNOWN       "unknown error"

#define ERR_INVCODE       "Invalid operation code"

#define ERR_USAGE          "Usage: ./philo 5 800 200 200 7"