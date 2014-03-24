/* Auto-generated by genmsg_cpp for file /home/lluis/fuerte/sandbox/aibo_server/msg/TouchArray.msg */
#ifndef AIBO_SERVER_MESSAGE_TOUCHARRAY_H
#define AIBO_SERVER_MESSAGE_TOUCHARRAY_H
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
struct TouchArray_ {
  typedef TouchArray_<ContainerAllocator> Type;

  TouchArray_()
  : header()
  , touch()
  {
  }

  TouchArray_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , touch(_alloc)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _touch_type;
  std::vector<double, typename ContainerAllocator::template rebind<double>::other >  touch;


  typedef boost::shared_ptr< ::aibo_server::TouchArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::aibo_server::TouchArray_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct TouchArray
typedef  ::aibo_server::TouchArray_<std::allocator<void> > TouchArray;

typedef boost::shared_ptr< ::aibo_server::TouchArray> TouchArrayPtr;
typedef boost::shared_ptr< ::aibo_server::TouchArray const> TouchArrayConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::aibo_server::TouchArray_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::aibo_server::TouchArray_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace aibo_server

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::aibo_server::TouchArray_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::aibo_server::TouchArray_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::aibo_server::TouchArray_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a25e66f7f3a5ee03b523486ae89ca221";
  }

  static const char* value(const  ::aibo_server::TouchArray_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xa25e66f7f3a5ee03ULL;
  static const uint64_t static_value2 = 0xb523486ae89ca221ULL;
};

template<class ContainerAllocator>
struct DataType< ::aibo_server::TouchArray_<ContainerAllocator> > {
  static const char* value() 
  {
    return "aibo_server/TouchArray";
  }

  static const char* value(const  ::aibo_server::TouchArray_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::aibo_server::TouchArray_<ContainerAllocator> > {
  static const char* value() 
  {
    return "#ROS header\n\
Header header\n\
\n\
#The IR of the Aibo\n\
float64[] touch\n\
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

  static const char* value(const  ::aibo_server::TouchArray_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::aibo_server::TouchArray_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::aibo_server::TouchArray_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::aibo_server::TouchArray_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.touch);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct TouchArray_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::aibo_server::TouchArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::aibo_server::TouchArray_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "touch[]" << std::endl;
    for (size_t i = 0; i < v.touch.size(); ++i)
    {
      s << indent << "  touch[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.touch[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // AIBO_SERVER_MESSAGE_TOUCHARRAY_H

