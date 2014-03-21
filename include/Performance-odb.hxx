// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PERFORMANCE_ODB_HXX
#define PERFORMANCE_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20200UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 2020000 // 2.2.0
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <odb/boost/date-time/pgsql/posix-time-traits.hxx>
//
// End prologue.

#include "Performance.h"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/no-id-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // Performance
  //
  template <>
  struct class_traits< ::Performance >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Performance >
  {
    public:
    typedef ::Performance object_type;
    typedef ::Performance* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef void id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_id_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_id_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>
#include <odb/pgsql/binding.hxx>
#include <odb/pgsql/pgsql-types.hxx>
#include <odb/pgsql/query.hxx>

namespace odb
{
  // Performance
  //
  template <typename A>
  struct query_columns< ::Performance, id_pgsql, A >
  {
    // Algorithm
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    Algorithm_type_;

    static const Algorithm_type_ Algorithm;

    // Implementation
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    Implementation_type_;

    static const Implementation_type_ Implementation;

    // ComputeStartTime
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::boost::posix_time::ptime,
        pgsql::id_timestamp >::query_type,
      pgsql::id_timestamp >
    ComputeStartTime_type_;

    static const ComputeStartTime_type_ ComputeStartTime;

    // TotalTime
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::uint64_t,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    TotalTime_type_;

    static const TotalTime_type_ TotalTime;

    // UserTime
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::uint64_t,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    UserTime_type_;

    static const UserTime_type_ UserTime;

    // SystemTime
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::uint64_t,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    SystemTime_type_;

    static const SystemTime_type_ SystemTime;

    // PercentTime
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::uint32_t,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    PercentTime_type_;

    static const PercentTime_type_ PercentTime;

    // IsDebug
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        bool,
        pgsql::id_boolean >::query_type,
      pgsql::id_boolean >
    IsDebug_type_;

    static const IsDebug_type_ IsDebug;
  };

  template <typename A>
  const typename query_columns< ::Performance, id_pgsql, A >::Algorithm_type_
  query_columns< ::Performance, id_pgsql, A >::
  Algorithm (A::table_name, "\"Algorithm\"", 0);

  template <typename A>
  const typename query_columns< ::Performance, id_pgsql, A >::Implementation_type_
  query_columns< ::Performance, id_pgsql, A >::
  Implementation (A::table_name, "\"Implementation\"", 0);

  template <typename A>
  const typename query_columns< ::Performance, id_pgsql, A >::ComputeStartTime_type_
  query_columns< ::Performance, id_pgsql, A >::
  ComputeStartTime (A::table_name, "\"ComputeStartTime\"", 0);

  template <typename A>
  const typename query_columns< ::Performance, id_pgsql, A >::TotalTime_type_
  query_columns< ::Performance, id_pgsql, A >::
  TotalTime (A::table_name, "\"TotalTime\"", 0);

  template <typename A>
  const typename query_columns< ::Performance, id_pgsql, A >::UserTime_type_
  query_columns< ::Performance, id_pgsql, A >::
  UserTime (A::table_name, "\"UserTime\"", 0);

  template <typename A>
  const typename query_columns< ::Performance, id_pgsql, A >::SystemTime_type_
  query_columns< ::Performance, id_pgsql, A >::
  SystemTime (A::table_name, "\"SystemTime\"", 0);

  template <typename A>
  const typename query_columns< ::Performance, id_pgsql, A >::PercentTime_type_
  query_columns< ::Performance, id_pgsql, A >::
  PercentTime (A::table_name, "\"PercentTime\"", 0);

  template <typename A>
  const typename query_columns< ::Performance, id_pgsql, A >::IsDebug_type_
  query_columns< ::Performance, id_pgsql, A >::
  IsDebug (A::table_name, "\"IsDebug\"", 0);

  template <typename A>
  struct pointer_query_columns< ::Performance, id_pgsql, A >:
    query_columns< ::Performance, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::Performance, id_pgsql >:
    public access::object_traits< ::Performance >
  {
    public:
    struct image_type
    {
      // Algorithm
      //
      details::buffer Algorithm_value;
      std::size_t Algorithm_size;
      bool Algorithm_null;

      // Implementation
      //
      details::buffer Implementation_value;
      std::size_t Implementation_size;
      bool Implementation_null;

      // ComputeStartTime
      //
      long long ComputeStartTime_value;
      bool ComputeStartTime_null;

      // TotalTime
      //
      long long TotalTime_value;
      bool TotalTime_null;

      // UserTime
      //
      long long UserTime_value;
      bool UserTime_null;

      // SystemTime
      //
      long long SystemTime_value;
      bool SystemTime_null;

      // PercentTime
      //
      int PercentTime_value;
      bool PercentTime_null;

      // IsDebug
      //
      bool IsDebug_value;
      bool IsDebug_null;

      std::size_t version;
    };

    using object_traits<object_type>::id;

    static bool
    grow (image_type&, bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static bool
    init (image_type&, const object_type&, pgsql::statement_kind);

    static void
    init (object_type&, const image_type&, database*);

    typedef pgsql::no_id_object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 8UL;
    static const std::size_t id_column_count = 0UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const char persist_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static const char persist_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];

    public:
  };

  template <>
  class access::object_traits_impl< ::Performance, id_common >:
    public access::object_traits_impl< ::Performance, id_pgsql >
  {
  };

  // Performance
  //
}

#include "Performance-odb.ixx"

#include <odb/post.hxx>

#endif // PERFORMANCE_ODB_HXX
