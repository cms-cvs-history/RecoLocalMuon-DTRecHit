#ifndef RecoLocalMuon_DTTTrigBaseSync_H
#define RecoLocalMuon_DTTTrigBaseSync_H

/** \class DTTTrigBaseSync
 *  Base class to define the offsets for 1D DT RecHit building
 *
 *  $Date: $
 *  $Revision: $
 *  \author G. Cerminara - INFN Torino
 */

#include "Geometry/Vector/interface/GlobalPoint.h"

class DTLayer;
class DTWireId;




class DTTTrigBaseSync {
public:
  /// Constructor
  DTTTrigBaseSync();

  /// Destructor
  virtual ~DTTTrigBaseSync();

  // Operations


  /// Time (ns) to be subtracted to the digi time.
  /// Parameters are the layer and the wireId to which the
  /// digi is referred and the estimation of
  /// the 3D hit position (globPos) 
  double offset(const DTLayer* layer,
		const DTWireId& wireId,
		const GlobalPoint& globalPos);



  /// Time to be subtracted to the digi time,
  /// Parameters are the layer and the wireId to which the
  /// digi is referred and the estimation of
  /// the 3D hit position (globPos)
  /// It also returns the different contributions separately:
  ///     - tTrig is the offset (t_trig)
  ///     - wirePropCorr is the delay for signal propagation along the wire
  ///     - tofCorr is the correction due to the particle TOF
  virtual double offset(const DTLayer* layer,
			const DTWireId& wireId,
			const GlobalPoint& globalPos,
			double &tTrig,
			double& wirePropCorr,
			double& tofCorr) = 0;



};
#endif

