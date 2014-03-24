/* Auto-generated by genmsg_cpp for file /home/lluis/fuerte/sandbox/aibo_server/msg/Accel.msg */
#ifndef AIBO_SERVER_MESSAGE_ACCEL_H
#define AIBO_SERVER_MESSAGE_ACCEL_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"

namespace aibo_server
{
template <class ContainerAllocator>
struct Accel_ {
  typedef Accel_<ContainerAllocator> Type;

  Accel_()
  : header()
  , x(0.0)
  , y(0.0)
  , z(0.0)
  {
  }

  Accel_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , x(0.0)
  , y(0.0)
  , z(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef double _x_type;
  double x;

  typedef double _y_type;
  double y;

  typedef double _z_type;
  double z;


  typedef boost::shared_ptr< ::aibo_server::Accel_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::aibo_server::Accel_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Accel
typedef  ::aibo_server::Accel_<std::allocator<void> > Accel;

typedef boost::shared_ptr< ::aibo_server::Accel> AccelPtr;
typedef boost::shared_ptr< ::aibo_server::Accel const> AccelConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::aibo_server::Accel_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::aibo_server::Accel_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace aibo_server

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::aibo_server::Accel_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::aibo_server::Accel_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::aibo_server::Accel_<ContainerAllocator> > {
  static const char* value() 
  {
    return "5defbd163657b4f6f639ba6d5676cc01";
  }

  static const char* value(const  ::aibo_server::Accel_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x5defbd163657b4f6ULL;
  static const uint64_t static_value2 = 0xf639ba6d5676cc01ULL;
};

template<class ContainerAllocator>
struct DataType< ::aibo_server::Accel_<ContainerAllocator> > {
  static const char* value() 
  {
    return "aibo_server/Accel";
  }

  static const char* value(const  ::aibo_server::Accel_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::aibo_server::Accel_<ContainerAllocator> > {
  static const char* value() 
  {
    return "#ROS header\n\
Header header\n\
\n\
#Whether the bumper is being pressed\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::aibo_server::Accel_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::aibo_server::Accel_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::aibo_server::Accel_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::aibo_server::Accel_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.x);
    stream.next(m.y);
    stream.next(m.z);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Accel_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::aibo_server::Accel_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::aibo_server::Accel_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
  }
};


} // namespace message_operations
} // namespace ros

#endif // AIBO_SERVER_MESSAGE_ACCEL_H

