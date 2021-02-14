from things.models import Thing,ThingInstance,ThingCategory
from things.serializers import ThingSerializer,ThingInstanceSerializer,ThingCategorySerializer
from rest_framework.viewsets import ModelViewSet
from rest_framework.permissions import IsAuthenticated

class ThingViewset(ModelViewSet):
    queryset = Thing.objects.all()
    serializer_class = ThingSerializer

    permission_classes = (IsAuthenticated,)


class ThingInstanceViewset(ModelViewSet):
    queryset = ThingInstance.objects.all()
    serializer_class = ThingInstanceSerializer

    permission_classes = (IsAuthenticated,)

class ThingCategoryViewset(ModelViewSet):
    queryset = ThingCategory.objects.all()
    serializer_class = ThingCategorySerializer

    permission_classes = (IsAuthenticated,)