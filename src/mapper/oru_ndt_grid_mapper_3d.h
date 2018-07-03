#ifndef CSLIBS_MAPPING_ORU_NDT_GRID_MAPPER_3D_H
#define CSLIBS_MAPPING_ORU_NDT_GRID_MAPPER_3D_H

#include <mutex>
#include <atomic>
#include <condition_variable>

#include <cslibs_mapping/mapper/mapper.hpp>
#include <cslibs_mapping/maps/oru_ndt_grid_map_3d.hpp>

#include <cslibs_math/statistics/distribution.hpp>

namespace cslibs_mapping {
namespace mapper {
class OruNDTGridMapper3D : public Mapper
{
public:
    virtual const inline map_t::ConstPtr getMap() const override;

private:
    virtual inline bool setupMap(ros::NodeHandle &nh) override;
    virtual inline bool uses(const data_t::ConstPtr &type) override;
    virtual inline void process(const data_t::ConstPtr &data) override;
    virtual inline bool saveMap() override;

    maps::OruNDTGridMap3D::Ptr map_;

    cslibs_math::statistics::Distribution<1,6> stats_;
    std::string stats_print_;
};
}
}

#endif // CSLIBS_MAPPING_ORU_NDT_GRID_MAPPER_3D_H