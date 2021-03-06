//READ LICENSE BEFORE ANY USAGE
/* Copyright (C) 2018  Damien DUBUC ddubuc@aneo.fr (ANEO S.A.S)
 *  Team Contact : hipe@aneo.fr
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *  
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *  
 *  In addition, we kindly ask you to acknowledge ANEO and its authors in any program 
 *  or publication in which you use HIPE. You are not required to do so; it is up to your 
 *  common sense to decide whether you want to comply with this request or not.
 *  
 *  Non-free versions of HIPE are available under terms different from those of the General 
 *  Public License. e.g. they do not require you to accompany any object code using HIPE 
 *  with the corresponding source code. Following the new licensing any change request from 
 *  contributors to ANEO must accept terms of re-license by a general announcement. 
 *  For these alternative terms you must request a license from ANEO S.A.S Company 
 *  Licensing Office. Users and or developers interested in such a license should 
 *  contact us (hipe@aneo.fr) for more information.
 */

#pragma once
#include <corefilter/Model.h>
#include <corefilter/tools/RegisterClass.h>
#include <corefilter/IFilter.h>

#include <core/HipeStatus.h>

#include <data/ImageData.h>

#pragma warning(push, 0)
#include <opencv2/imgproc.hpp>
#include <opencv2/photo.hpp>	
#include "algos/show/WriteText.h"

#pragma warning(pop)

namespace data {
	class ImageData;
}

namespace filter
{
	namespace algos
	{
		class WriteVideo : public filter::IFilter
		{
			SET_NAMESPACE("vision/utils")

				CONNECTOR(data::ImageData, data::ImageData);

			REGISTER(WriteVideo, ()), _connexData(data::INDATA)
			{
				_debug = 0;
				skip_frame = 0;
				id = -1;
				count = 0;
				dir_path = "videos";
				fps_avg = 25;
				url = "";
			}

			int id;
			int count;
			cv::VideoWriter writer;

			REGISTER_P(int, _debug);

			REGISTER_P(int, skip_frame);

			REGISTER_P(int, fps_avg);

			REGISTER_P(std::string, dir_path);

			REGISTER_P(std::string, prefix_filename);
			REGISTER_P(std::string, url);

			

			int getLastKnownIDFromDirectory();

			HipeStatus process() override;


			void dispose()
			{
				if (writer.isOpened())
				{
					writer.release();
				}
			}
		};

		ADD_CLASS(WriteVideo, _debug, skip_frame, fps_avg, dir_path, prefix_filename, url);


	}
}